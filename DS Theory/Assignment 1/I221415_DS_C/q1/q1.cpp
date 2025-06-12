#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;
//```````````````````````````````````````````````````````````````````````````` Segment ````````````````````````````````````````````````````````````````````````
struct segment
{
    int address;
    string data;
    segment()
    {
        address = NULL;
        data = "";
    }
};

//```````````````````````````````````````````````````````````````````````````` Node ````````````````````````````````````````````````````````````````````````
struct Node
{
    int address;
    string data;
    bool is_modified;
    Node* next;

    Node(int a, string d)
    {
        address = a;
        data = d;
        is_modified = false;
        next = nullptr;
    }
};

//```````````````````````````````````````````````````````````````````````````` Read CSV ````````````````````````````````````````````````````````````````````````
segment* read_csv(const string& f, int& s)
{
    ifstream file(f);
    string line;
    s = 0;
    segment* memory = new segment[100];
    //reading the Csv
    while (getline(file, line))
    {
        if (!line.empty())
        {
            stringstream ss(line);
            int address;
            string data;
            ss >> address >> data;
            memory[s].address = address;
            memory[s].data = data;
            s++;
        }
    }
    file.close();
    return memory;
}
//```````````````````````````````````````````````````````````````````````````` Update CSV ````````````````````````````````````````````````````````````````````````
void update_csv(const string& f, segment* m, int s)
{
    ofstream file(f);
    for (int i = 0; i < s; i++)
    {
        file << m[i].address << "\t" << m[i].data << endl;
    }
    file.close();
}
//```````````````````````````````````````````````````````````````````````````` Cache ````````````````````````````````````````````````````````````````````````
class cache
{
    Node* head;
    int max_size;
    int curr_size;

public:
    cache(int s)
    {
        head = nullptr;
        max_size = s;
        curr_size = 0;
    }
    //Found
    Node* locate(int a)
    {
        Node* temp = head;
        while (temp)
        {
            if (temp->address == a)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
    //Insert
    void insert(int a, string d)
    {
        if (curr_size >= max_size)
        {
            remove_cache();
        }
        Node* newNode = new Node(a, d);
        newNode->next = head;
        head = newNode;
        curr_size++;
    }
    //Removing Cache
    void remove_cache()
    {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp && temp->next)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp->is_modified)
        {
            cout << "Write back to memory." << endl;
        }

        if (prev)
        {
            prev->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete temp;
        curr_size--;
    }
    //Display
    void display()
    {
        Node* temp = head;
        cout << "\t\t\t\t\t_________________" << endl;
        cout << "\t\t\t\t\t| Cache Details |" << endl;
        cout << "\t\t\t\t\t|_______________|" << endl << endl << endl;
        while (temp)
        {
            cout << "Address: " << temp->address << ", Data: " << temp->data << ", Modified: " << temp->is_modified << endl;
            temp = temp->next;
        }
    }
};
//```````````````````````````````````````````````````````````````````````````` Load Operation ````````````````````````````````````````````````````````````````````````
void operation_load(cache& c, int a, segment* m, int s)
{
    Node* node = c.locate(a);
    if (node)
    {
        cout << "Address " << a << " found in cache." << endl;
    }
    else
    {
        cout << "Address " << a << " not found in cache." << endl;

        string data = "";
        for (int i = 0; i < s; i++)
        {
            if (m[i].address == a)
            {
                data = m[i].data;
                cout << "Found data " << data << " for address " << a << endl;
                break;
            }
        }

        if (data.empty())
        {
            cout << "Address " << a << " not found in memory!" << endl;
            return;
        }

        c.insert(a, data);
        cout << "Address " << a << " with data inserted." << data << endl;
    }
}
//```````````````````````````````````````````````````````````````````````````` Store Operations ````````````````````````````````````````````````````````````````````````
void operation_store(cache& c, int a, string d, segment* m, int s, bool w)
{
    Node* node = c.locate(a);
    if (node)
    {
        if (w)
        {
            cout << "Updating cache and memory." << endl;
            node->data = d;
            for (int i = 0; i < s; i++)
            {
                if (m[i].address == a)
                {
                    m[i].data = d;
                    break;
                }
            }
        }
        else
        {
            cout << "Updating cache only." << endl;
            node->data = d;
            node->is_modified = true;
        }
    }
    else
    {
        cout << " Address " << a << " not found in cache." << endl;
        if (w)
        {
            cout << " Loading data into cache and updating memory." << endl;
            c.insert(a, d);
            for (int i = 0; i < s; i++)
            {
                if (m[i].address == a)
                {
                    m[i].data = d;
                    break;
                }
            }
        }
        else
        {
            cout << " Writing directly to memory without updating cache." << endl;
            for (int i = 0; i < s; i++)
            {
                if (m[i].address == a)
                {
                    m[i].data = d;
                    break;
                }
            }
        }
    }
}
//```````````````````````````````````````````````````````````````````````````` Main ````````````````````````````````````````````````````````````````````````
int main()
{
    cout << "\033[1;33m";
    cout << "\t\t\t\t\t_________________" << endl;
    cout << "\t\t\t\t\t| Cache Control |" << endl;
    cout << "\t\t\t\t\t|_______________|" << endl << endl << endl;
    string file_name = "memory.csv";
    int s;
    segment* obj = read_csv(file_name, s);

    int a;
    cout << "Enter cache size: ";
    cin >> a;
    cache obj1(a);
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t____________________" << endl;
    cout << "\t\t\t\t\t| Cache Hit Policy |" << endl;
    cout << "\t\t\t\t\t|__________________|" << endl << endl;
    bool b;
    cout << "Select:" << endl;
    cout << "0) Write Through" << endl;
    cout << "1) Write Back" << endl;
    cout << endl;
    cout << "Enter: ";
    cin >> b;
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t_____________________" << endl;
    cout << "\t\t\t\t\t| Cache Miss Policy |" << endl;
    cout << "\t\t\t\t\t|___________________|" << endl << endl;
    bool c;
    cout << "Select:" << endl;
    cout << "0) Write Allocate" << endl;
    cout << "1) Write Around" << endl;
    cout << endl;
    cin >> c;

    int addr;
    string data;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Enter address to load: ";
    cin >> addr;
    operation_load(obj1, addr, obj, s);
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Enter address and data to store (hex): ";
    cin >> addr >> data;
    operation_store(obj1, addr, data, obj, s, b);
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    update_csv(file_name, obj, s);

    delete[] obj;
    return 0;
}