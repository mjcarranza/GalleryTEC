#include <iostream>
#include <fstream>
#include "StorageManager.h"
#include <vector>
#include <bitset>
#include <glob.h>

using namespace std;

StorageManager::StorageManager(){
    cout<<"Storage manager created"<<endl;
}

string xoring(string a, string b, int n){
    string ans;

    for(int i = 0; i < n;i++){
        ans += (bitset<1>(a[i])^bitset<1>(b[i])).to_string();
    }
    return ans;
}
void StorageManager::save(const std::string& name, const std::string& content) {

    //calculation of the slice size and the place for the parity slice
    const int slice_size = (content.length()*8)/4;
    int parity_place = amount_of_drives - (currStripe%5)+1;
    cout<<"slice_ size calculated: "<<slice_size<<endl;

    //create vector with the charachters of the input string content
    vector<char> content_char;
    for(int i = 0; i<=content.length();i++){
        content_char.push_back(content[i]);
    }
    cout<<"content_char created and populated"<<endl;

    //create a string with the binary ascii codes for the characters
    string content_string_binary;
    for(char i : content_char){
        string character = bitset<8>(i).to_string();
        content_string_binary+=character;
    }
    //cout<<"content_string_binary created: "<<content_string_binary<<endl;

    //divides the raw data in slices and calculates the parity slice
    string slices[4];
    string parity_slice = content_string_binary.substr(0,slice_size);
    for(int i = 0; i<=4; i++){
        slices[i] = content_string_binary.substr(i*slice_size,slice_size);
        parity_slice = xoring(parity_slice, content_string_binary.substr(i*slice_size,slice_size),slice_size);
    }
    //cout<<"parity_slice calculated: "<<parity_slice<<endl;

    //cout<<"slices array created"<<endl;
    for(int i = 0; i<4;i++){
        cout<<"slice: "<<i<<endl;
        cout<<slices[i]<<endl;
    }

    //saves the striped file with the parity slice in an array with the order it is going to be saved in the RAID 5 configuration with 5 disks
    string striped_file[amount_of_drives];
    for(int i=0; i<amount_of_drives; i++){
        if (i+1==parity_place){
            striped_file[i]=parity_slice;
        } else {
            striped_file[i]=slices[i];
        }
    }
    //cout<<"stripped_file array created"<<endl;
    for(int i = 0; i<5;i++){
        cout<<"slice: "<<i<<endl;
        cout<<striped_file[i]<<endl;
    }

    //
    for(int i = 0; i<amount_of_drives;i++){
        ofstream striped_data (drives[i][0]+"/"+name+".txt");
        if (striped_data.is_open()){
            striped_data<<striped_file[i]+'\n';
            striped_data.close();
        }
    }
    currStripe++;
    cout<<"File Saved in RAID5!"<<endl;
}

string StorageManager::getFile(std::string filename) {
    string file_path=drives[0][0]+filename;
    glob_t globbuf;

    //
    string partial_path = file_path + "*.txt";
    glob(partial_path.c_str(), 0, NULL, &globbuf);
    for (size_t i = 0;i < globbuf.gl_pathc;i++){
        cout << "found: " << globbuf.gl_pathv[i]<<endl;
        ifstream f(globbuf.gl_pathv[i]);
        if(f.good()) {
            cout<<"File good"<<endl;
            //path of the file
            string path = globbuf.gl_pathv[i];

            //Local parity location
            int local_parity_place = stoi(path.substr(path.find(filename)+filename.length()+1, path.length()-(path.find(filename)+filename.length()+1)-4));

            string complete_filename = path.substr(path.find(filename), 9999999);

            string raiddata[5];

            //getting the raw data in the raid into an array
            for(int t = 0; t < 5; t++){
                raiddata[t]= drives[t][0] + "/" + complete_filename;
            }

            string local_file_content;

            for(int j=0; j < 5; j++){
                if(j != local_parity_place - 1){
                    local_file_content+=raiddata[j];
                }
            }
            break;
        }
    }
    cout<<"finished looking"<<endl;

}