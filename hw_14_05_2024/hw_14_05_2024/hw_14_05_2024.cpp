#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileManager
{
    static FileManager* instance;

    FileManager() {}
public:
    static FileManager* GetInstance()
    {
        if (instance == nullptr)
        {
            instance = new FileManager();
        }
        return instance;
    }

    void CreateFile(string fileName)
    {
        ofstream file(fileName);
        if (file)
        {
            cout << "File created: " << fileName << "\n";
        }
        else
        {
            cout << "Failed to create file: " << fileName << "\n";
        }
    }

    void OpendFile(string fileName)
    {
        fstream file(fileName);
        file.open(fileName, fstream::app);
        cout << "File is open\n";
    }

    void CloseFile(string fileName)
    {
        ofstream file(fileName);
        cout << "File closed\n";
        file.close();
    }

    void DestroyFile(const char* fileName)
    {
        remove(fileName);
    }

    void Write(string fileName, string message)
    {
        ofstream file(fileName, ios::app);

        if (file.is_open())
        {
            cout << "Wtitting to file\n";
            file << message << "\n";
        }
        else
        {
            cout << "Failed to write to file\n";
        }
    }

    string RedLine(const char* fileName)
    {
        ifstream file(fileName);

        if (!file)
        {
            cout << "Error file closed\n";

        }

        string line;
        getline(file, line);
        return line;
    }

    string ReadFile(const char* fileName)
    {
        ifstream file(fileName);
        string current;
        string line;

        while (getline(file, line))
        {
            current += line;
        }
        return current;
    }
};

FileManager* FileManager::instance = nullptr;

int main()
{
    const char* file = "file.txt";
    auto ptr = FileManager::GetInstance();
    ptr->CreateFile(file);

    ptr->Write(file, "hello world");
    cout << ptr->ReadFile(file);
}
