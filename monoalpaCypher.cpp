#include<iostream>
using namespace std;

void encryption(string msg, int key)
{
    string cypher_text;
    int i,len = msg.length();
    for(i=0;i<len;i++)
    {
        if(msg[i]==' ')
        {
            cypher_text.push_back(' ');
            continue;
        }
        cypher_text.push_back(char(int(msg[i])-key));
    }
    cout<<cypher_text;

}

void decryption(string msg, int key)
{
    string plain_text;
    int i,len = msg.length();
    for(i=0;i<len;i++)
    {
        if(msg[i]==' ')
        {
            plain_text.push_back(' ');
            continue;
        }
        plain_text.push_back(char(int(msg[i])+key));
    }
    cout<<plain_text;

}

int main()
{
    string messege;
    int choice,key;
    cout<<"What do you want to do?"<<endl<<"1.Encryption"<<endl<<"2.Decryption"<<endl;
    cout<<"Enter Choice: ";     cin>>choice;
    cout<<"Enter text: ";     getline(cin>>ws,messege);
    cout<<"Enter key: ";    cin>>key;

    if(choice==1)encryption(messege,key);
    else if(choice==2)decryption(messege,key);
    else cout<<"Wrong command";

}
