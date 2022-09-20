
#include<iostream>
#include<string>
#include<vector>

using namespace std;
string char_to_binay_stream(char x);
string generate_string_128bit(int len);
string generate_input(string input, string bit_128);
vector <string> generate_blocks(string total_msg);
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
string sha_512(vector <string> blocks);
void f_function(string block);
void round_function(int round_num);
string t1(int i);
string t2();
string bit_string_to_hex_string(string input);
string bit_to_hex(string input);

string words[80];
string key[80] =
{"428a2f98d728ae22", "7137449123ef65cd",
"b5c0fbcfec4d3b2f", "e9b5dba58189dbbc",
"3956c25bf348b538", "59f111f1b605d019",
"923f82a4af194f9b", "ab1c5ed5da6d8118",
"d807aa98a3030242", "12835b0145706fbe",
"243185be4ee4b28c", "550c7dc3d5ffb4e2",
"72be5d74f27b896f", "80deb1fe3b1696b1",
"9bdc06a725c71235", "c19bf174cf692694",
"e49b69c19ef14ad2", "efbe4786384f25e3",
"0fc19dc68b8cd5b5", "240ca1cc77ac9c65",
"2de92c6f592b0275", "4a7484aa6ea6e483",
"5cb0a9dcbd41fbd4", "76f988da831153b5",
"983e5152ee66dfab", "a831c66d2db43210",
"b00327c898fb213f", "bf597fc7beef0ee4",
"c6e00bf33da88fc2", "d5a79147930aa725",
"06ca6351e003826f", "142929670a0e6e70",
"27b70a8546d22ffc", "2e1b21385c26c926",
"4d2c6dfc5ac42aed", "53380d139d95b3df",
"650a73548baf63de", "766a0abb3c77b2a8",
"81c2c92e47edaee6", "92722c851482353b",
"a2bfe8a14cf10364", "a81a664bbc423001",
"c24b8b70d0f89791", "c76c51a30654be30",
"d192e819d6ef5218", "d69906245565a910",
"f40e35855771202a", "106aa07032bbd1b8",
"19a4c116b8d2d0c8", "1e376c085141ab53",
"2748774cdf8eeb99", "34b0bcb5e19b48a8",
"391c0cb3c5c95a63", "4ed8aa4ae3418acb",
"5b9cca4f7763e373", "682e6ff3d6b2b8a3",
"748f82ee5defb2fc", "78a5636f43172f60",
"84c87814a1f0ab72", "8cc702081a6439ec",
"90befffa23631e28", "a4506cebde82bde9",
"bef9a3f7b2c67915", "c67178f2e372532b",
"ca273eceea26619c", "d186b8c721c0c207",
"eada7dd6cde0eb1e", "f57d4f7fee6ed178",
"06f067aa72176fba", "0a637dc5a2c898a6",
"113f9804bef90dae", "1b710b35131c471b",
"28db77f523047d84", "32caab7b40c72493",
"3c9ebe0a15c9bebc", "431d67c49c100d4c",
"4cc5d4becb3e42b6", "597f299cfc657e2a",
"5fcb6fab3ad6faec", "6c44198c4a475817"};

//string key[80];


string a1=hex_string_to_bit("6A09E667F3BCC908");
string b1=hex_string_to_bit("BB67AE8584CAA73B");
string c1=hex_string_to_bit("3C6EF372FE94F82B");
string d1=hex_string_to_bit("A54FF53A5F1D36F1");
string e1=hex_string_to_bit("510E527FADE682D1");
string f1=hex_string_to_bit("9B05688C2B3E6C1F");
string g1=hex_string_to_bit("1F83D9ABFB41BD6B");
string h1=hex_string_to_bit("5BE0CDI9137E2179");

string a=hex_string_to_bit("6A09E667F3BCC908");
string b=hex_string_to_bit("BB67AE8584CAA73B");
string c=hex_string_to_bit("3C6EF372FE94F82B");
string d=hex_string_to_bit("A54FF53A5F1D36F1");
string e=hex_string_to_bit("510E527FADE682D1");
string f=hex_string_to_bit("9B05688C2B3E6C1F");
string g=hex_string_to_bit("1F83D9ABFB41BD6B");
string h=hex_string_to_bit("5BE0CDI9137E2179");
//wertuitrewsnmbvccvbktwertopoiutrewsfjkl;kjhgfdsa/.,mnbvcxziuytrewquio[poiuytrewq;lkjhgfdsaqwertyuiopiukjhnbuyhgbvtrgfdvcxrefdscxzpolikjmhngbvcxzasdcvb werdfghbnmtyuhjkm,.][p';olk,jmnoikujhngbfvytgrfdcsxzrfdesazqawsdvcfberdfghmntyjhk.,][p';olkjmhngbokijhgbfvctgfds
int main()
{

    vector <string> aa;
    string input, total_msg, out_input,result;
    cout<<"Enter String : "<<endl;
    getline(cin,input);
    int i,j,l=input.length();
    for(i=0;i<l;i++)
    out_input = out_input + char_to_binay_stream(input[i]);

    total_msg = generate_input(out_input,generate_string_128bit(l));

    //cout<<"total msg: "<<total_msg<<"   "<<total_msg.length()<<endl;
    aa = generate_blocks(total_msg);
    result = sha_512(aa);
   // cout<<total_msg<<" "<<total_msg.length()/1024;
    cout<<"\n\nYour 512 bit hash code of the string is: \n"<<result<<endl<<endl<<"In HEx: "<<bit_string_to_hex_string(result)<<endl<<endl;
        //cout<<q<<endl<<endl<<endl;



   // cout<<shr("abcde",3);

  // cout<<a<<"   "<<b;
    return 0;




}

string sha_512(vector <string> blocks)
{
    int block_num = blocks.size(),i;

    for(i=0;i<block_num-1;i++)
    {
       // cout<<i+1<<" "<<"BLOCK"<<endl<<blocks[i]<<endl;
        f_function(blocks[i]);
    }

    return a+b+c+d+e+f+g+h;
}

void f_function(string block)
{
    a1 = a;
    b1 = b;
    c1 = c;
    d1 = d;
    e1 = e;
    f1 = f;
    g1 = g;
    h1 = h;

    generate_word(block);

    for(int i=0;i<80;i++)
    {
        round_function(i);
    }

    a = do_xor(a,a1);
    b = do_xor(b,b1);
    c = do_xor(c,c1);
    d = do_xor(d,d1);
    e = do_xor(e,e1);
    f = do_xor(f,f1);
    g = do_xor(g,g1);
    h = do_xor(h,h1);

}

void round_function(int round_num)
{
    string ta,tb,tc,td,te,tf,tg,th;

    ta= do_xor(t1(round_num),t2());
    tb = a;
    tc = b;
    td = c;
    te = do_xor(d,t1(round_num));
    tf = e;
    tg = f;
    th = g;

    a = ta;
    b = tb;
    c = tc;
    d = td;
    e = te;
    f = tf;
    g = tg;
    h = th;
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
    return do_xor(do_xor(h,ch()),do_xor(do_xor(words[i],hex_string_to_bit(key[i])),sum1e()));
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

vector <string> generate_blocks(string total_msg)
{
    vector <string> output;
    int strat =0;

    for(;strat<=total_msg.length();)
    {
        output.push_back(total_msg.substr(strat,1024));
        strat = strat + 1024;
    }

    return output;
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

string bit_string_to_hex_string(string input)
{
    int l=input.length(),start=0;
    string output;
    while(true)
    {
        output = output + bit_to_hex(input.substr(start,4));
        start=start+4;

        if(start==l)
            break;
    }
    return output;
}

string bit_to_hex(string input)
{
    if(input=="0001")
        return "1";
    else if(input=="0010")
        return "2";
    else if(input=="0011")
        return "3";
    else if(input=="0100")
        return "4";
    else if(input=="0101")
        return "5";
    else if(input=="0101")
        return "6";
    else if(input=="0110")
        return "7";
    else if(input=="1000")
        return "8";
    else if(input=="1001")
        return "9";
    else if(input=="1010")
        return "A";
    else if(input=="1011")
        return "B";
    else if(input=="1100")
        return "C";
    else if(input=="1101")
        return "D";
    else if(input=="1110")
        return "E";
    else if(input=="1111")
        return "F";
}


