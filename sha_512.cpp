
#include<iostream>
#include<string>
#include<vector>

using namespace std;
string char_to_binay_stream(char x);
string generate_string_128bit(int len);
string generate_input(string input, string bit_128);
string rotr(string taken_string, int rot);
string shr(string taken_string, int rot);
string do_xor(string a, string b);
string do_and(string a, string b);
string sigma_zero(string taken_string);
string sigma_one(string taken_string);
void generate_word(string block);
string do_not(string a);
string hex_string_to_bit(string input);
string ch();
string maj();
string sum0a();
string sum1e();

string words[80];
string key[80];
string a=hex_string_to_bit("6A09E667F3BCC908");
string b=hex_string_to_bit("BB67AE8584CAA73B");
string c=hex_string_to_bit("3C6EF372FE94F82B");
string d=hex_string_to_bit("A54FF53A5F1D36F1");
string e=hex_string_to_bit("510E527FADE682D1");
string f=hex_string_to_bit("9B05688C2B3E6C1F");
string g=hex_string_to_bit("1F83D9ABFB41BD6B");
string h=hex_string_to_bit("5BE0CDI9137E2179");

int main()
{
/*
    vector <string> aa;
    string input, output, out_input;
    getline(cin,input);
    int i,l=input.length();
    for(i=0;i<l;i++)
    out_input = out_input + char_to_binay_stream(input[i]);

    string a= generate_input(out_input,generate_string_128bit(out_input.length()));

    int block_num = a.length()/1024, start=0;

    for(i=0;i<block_num;i++)
    {
        cout<<endl<<endl<<"For block num: "<<i+1<<endl;
        generate_word(a.substr(start,1024));
        for(auto q:aa)
            cout<<q<<endl;

        start = start +1024;

    }*/



   // cout<<shr("abcde",3);

   cout<<a<<"   "<<b;
    return 0;
}

string rotr(string taken_string, int rot)
{
    string temp_string;
    int l=taken_string.length();

    temp_string = taken_string.substr(l-(rot%l),l) + taken_string.substr(0,l-(rot%l));
    return temp_string;
}

string shr(string taken_string, int rot)
{
    string temp_string;
    int l =taken_string.length(),i;
    temp_string = taken_string.substr((rot%l),l);

    for(i=0;i<(rot%l);i++)
        temp_string = temp_string + "0";

    return temp_string;

}


string sigma_zero(string taken_string)
{
    string temp_string;
    temp_string = do_xor(do_xor(rotr(taken_string,1),rotr(taken_string,8)),shr(taken_string,7));
    return temp_string;
}

string sigma_one(string taken_string)
{
    string temp_string;
    temp_string = do_xor(do_xor(rotr(taken_string,19),rotr(taken_string,61)),shr(taken_string,6));
    return temp_string;
}

void generate_word(string block)
{
    int i,s=0;
    for(i=0;i<80;i++)
    {
        if(i<16)
        {
            //words.push_back(block.substr(s,64));
            words[i]=block.substr(s,64);
            s=s+64;
        }
        else
        {
            words[i]=(do_xor(do_xor(sigma_one(words[i-2]),sigma_zero(words[i-15])),do_xor(words[i-7],words[i-16])));
        }
    }

    //return words;

}


string ch()
{
    return do_xor(do_and(e,f),do_and(do_not(e),g));
}

string maj()
{
    return do_xor(do_xor(do_and(a,b),do_and(a,c)),do_and(b,c));
}

string sum0a()
{
    return do_xor(do_xor(rotr(a,28),rotr(a,34)),rotr(a,39));
}

string sum1e()
{
    return do_xor(do_xor(rotr(e,14),rotr(e,18)),rotr(e,41));
}

string t1(int i)
{
    return do_xor(do_xor(h,ch()),do_xor(do_xor(words[i],key[i]),sum1e()));
}

string t2()
{
    return do_xor(sum0a(),maj());
}


string char_to_binay_stream(char x)
{
    int d = (int)x, remainder, div=128;
    string stream;
    while(div>=1)
    {
        if(d>=div)
        {
            stream = stream + "1";
            d=d-div;
        }
        else
            stream = stream + "0";
        div = div/2;

    }

    return stream;
}

string generate_string_128bit(int d)
{
    string stream,s;
    int div=16384,l;
    while(div>=1)
    {
        if(d>=div)
        {
            stream = stream + "1";
            d=d-div;
        }
        else
            stream = stream + "0";
        div = div/2;

    }

    for(int i=0;i<(128-15);i++)
    {
        s =s+"0";
    }
    stream = s+stream;
    return stream;
}

string generate_input(string input, string bit_128)
{
    int l1 = input.length(),required_len=1024,pad_len;
    string s;
    while(true)
    {
        if(l1+128<=required_len)
        {
            pad_len= required_len-(l1+128);
            break;
        }
        else
            required_len = required_len*2;
    }
    s= s+input+"1";
    for(int i=0;i<(pad_len-1);i++)
    {
        s =s+"0";
    }
    s=s+bit_128;

    return s;

}


string do_xor(string a, string b)
{
    int l= a.length();
    string temp_string;

    for(int i=0;i<l;i++)
    {
        if(a[i]=='0'&&b[i]=='0')
            temp_string = temp_string + "0";
        else if(a[i]=='0'&&b[i]=='1')
            temp_string = temp_string + "1";
        else if(a[i]=='1'&&b[i]=='0')
            temp_string = temp_string + "1";
        else
            temp_string = temp_string + "0";

    }

    return temp_string;
}


string do_and(string a, string b)
{
    int l= a.length();
    string temp_string;

    for(int i=0;i<l;i++)
    {
        if(a[i]=='0'&&b[i]=='0')
            temp_string = temp_string + "0";
        else if(a[i]=='0'&&b[i]=='1')
            temp_string = temp_string + "0";
        else if(a[i]=='1'&&b[i]=='0')
            temp_string = temp_string + "0";
        else
            temp_string = temp_string + "1";

    }

    return temp_string;
}

string do_not(string a)
{
    int l= a.length();
    string temp_string;

    for(int i=0;i<l;i++)
    {
        if(a[i]=='0')
            temp_string = temp_string + "1";
        else
            temp_string = temp_string + "0";
    }

    return temp_string;
}

string hex_string_to_bit(string input)
{
    string output;
    for(int i=0;i<input.length();i++)
    {
        if(input[i]=='1')
            output = output + "0001";
        else if(input[i]=='2')
            output = output + "0010";
        else if(input[i]=='1')
            output = output + "0001";
        else if(input[i]=='3')
            output = output + "0011";
        else if(input[i]=='4')
            output = output + "0100";
        else if(input[i]=='5')
            output = output + "0101";
        else if(input[i]=='6')
            output = output + "0110";
        else if(input[i]=='7')
            output = output + "0111";
        else if(input[i]=='8')
            output = output + "1000";
        else if(input[i]=='9')
            output = output + "1001";
        else if(input[i]=='a'||input[i]=='A')
            output = output + "1010";
        else if(input[i]=='b'||input[i]=='B')
            output = output + "1011";
        else if(input[i]=='c'||input[i]=='C')
            output = output + "1100";
        else if(input[i]=='d'||input[i]=='D')
            output = output + "1101";
        else if(input[i]=='e'||input[i]=='E')
            output = output + "1110";
        else
            output = output + "1111";

    }

    return output;
}


