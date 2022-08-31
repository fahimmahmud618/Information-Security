#include<iostream>
using namespace std;
char table[26][10]={'a','b','c','d','e','f','g','h','i','j',
                    'b','c','d','e','f','g','h','i','j','k',
                    'c','d','e','f','g','h','i','j','k','l',
                    'd','e','f','g','h','i','j','k','l','m',
                    'e','f','g','h','i','j','k','l','m','n',
                    'f','g','h','i','j','k','l','m','n','o',
                    'g','h','i','j','k','l','m','n','o','p',
                    'h','i','j','k','l','m','n','o','p','q',
                    'i','j','k','l','m','n','o','p','q','r',
                    'j','k','l','m','n','o','p','q','r','s',
                    'k','l','m','n','o','p','q','r','s','t',
                    'l','m','n','o','p','q','r','s','t','u',
                    'm','n','o','p','q','r','s','t','u','v',
                    'n','o','p','q','r','s','t','u','v','w',
                    'o','p','q','r','s','t','u','v','w','x',
                    'p','q','r','s','t','u','v','w','x','y',
                    'q','r','s','t','u','v','w','x','y','z',
                    'r','s','t','u','v','w','x','y','z','!',
                    's','t','u','v','w','x','y','z','!','@',
                    't','u','v','w','x','y','z','!','@','#',
                    'u','v','w','x','y','z','!','@','#','$',
                    'v','w','x','y','z','!','@','#','$','%',
                    'w','x','y','z','!','@','#','$','%','^',
                    'x','y','z','!','@','#','$','%','^','&',
                    'y','z','!','@','#','$','%','^','&','&',
                    'z','!','@','#','$','%','^','&','&','*'
                    };

void encryption(string msg)
{
    string cypher_text;
    int i,j,len = msg.length();
    for(i=0;i<len;i++)
    {
        if(msg[i]==' ')
        {
            cypher_text.push_back(' ');
            continue;
        }
        j = i%10;
        cypher_text.push_back(table[((int)msg[i])-97][j]);
    }
    cout<<cypher_text;

}

void decryption(string msg)
{
    string plain_text;
    int i,j,k,len = msg.length();
    for(i=0;i<len;i++)
    {
        if(msg[i]==' ')
        {
            plain_text.push_back(' ');
            continue;
        }
        for(j=0;j<26;j++)
        {
            k = i%10;
            if(msg[i]==table[j][k])
                break;
        }
        plain_text.push_back(char(97+j));
    }
    cout<<plain_text;

}
int main()
{
    string messege;
    int choice;
    cout<<"What do you want to do?"<<endl<<"1.Encryption"<<endl<<"2.Decryption"<<endl;
    cout<<"Enter Choice: ";     cin>>choice;
    cout<<"Enter text: ";     getline(cin>>ws,messege);

    if(choice==1)encryption(messege);
    else if(choice==2)decryption(messege);
    else cout<<"Wrong command";
}
