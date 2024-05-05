#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SecurityTool {
protected:
    string securityLevel;
    double cost;
    int devices;

public:
    SecurityTool(string level, double rate, int dev) : securityLevel(level), cost(rate), devices(dev) {
        if (securityLevel != "High" && securityLevel != "Low" && securityLevel != "Medium") {
            cout << "Enter valid level..." << endl;
            exit(1);
        }

        if (cost <= 0) {
            cout << "The cost cannot be that low..." << endl;
            exit(1);
        }
    }

    virtual void performScan() {
        cout << "Performing a generic security scan..." << endl;
    }
};

class FirewallTool : public SecurityTool {
    vector<int> ports;
    int roll;
    vector<string> protocols;

public:
    FirewallTool(vector<int> port, int r = 6, vector<string> pro = {})
        : SecurityTool("High", 50, 10), roll(r), ports(port), protocols(pro) {
        for (int i = r; i < r + 23; i++) {
            ports.push_back(port[i]);
        }
    }

    void performScan() override {
        cout << "Performing a security scan..." << endl;

        if (securityLevel == "High") {
            cout << "High security level: Allowing traffic from port list and protocol list only." << endl;
        } else if (securityLevel == "Medium") {
            cout << "Medium security level: Allowing traffic from port list, protocol list, and the next two ports in sequence." << endl;
        } else if (securityLevel == "Low") {
            cout << "Low security level: Allowing traffic from port list, protocol list, the next 5 ports in sequence, and from TCP and DNS protocol." << endl;
        } else {
            cout << "Invalid security level." << endl;
        }
    }
};

int main() {
    vector<int> portList = {80, 443, 21, 22, 25, 53, 161, 162, 20, 23, 69, 123, 137, 138, 139, 161, 162, 69, 161, 162, 514, 22, 23};
    vector<string> protocolList = {"HTTPS", "FTP", "UDP", "ICMP", "SSH", "SNMP"};
    FirewallTool firewall(portList, 6, protocolList);
    firewall.displayPortList();
    firewall.performScan();

    return 0;
}

