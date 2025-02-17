#include "server.h"
#include "client.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << "<server|client>" << endl;
        return 1;
    }

    string mode = argv[1];

    if (mode == "server") {
        Server server(8000);
        server.start();
    }

    else if (mode == "client") {
        Client client("127.0.0.1", 8000);
        client.sendMessage("Hey");
    }

    else {
        cerr << "Not correct Mode" << endl;
        return 1;
    }
    return 0;
}
