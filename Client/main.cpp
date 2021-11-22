#include "Client.h"

Client* client;

void * clientRun(void *){
    const char *Ip = "127.0.0.1";
    int port = 4050;
    try {
        client->Connect(Ip,port);
    } catch (string ex) {
        cout<< ex <<endl;
    }
    pthread_exit(nullptr);
}

int main() {
    client = new Client();
    pthread_t hiloClient;
    pthread_create(&hiloClient,0,clientRun,nullptr);
    pthread_detach(hiloClient);

    while (true){
        cout<<"leyendo mensajes"<<endl;
        string json;
        cin>>json;
        if (json == "salir"){
            break;
        }
        client->setMessage(json.c_str());
    }
    delete client;

    return 0;
}
