#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int mx,n;
//number of fanout

struct node_structure
{
    int current_node;
    node_structure *parent_node, *its_next_node;
    node_structure **point;
    bool leaf_or_not;
    string *word, *meaning;

};

node_structure *root_node, *first_leaf_node;

node_structure* create_new_node()
{
    node_structure *nd = new node_structure();

    nd->point = new node_structure *[n+1];
    nd->word = new string[n];
    nd->meaning = new string[n];
    nd->current_node = 0;
    nd->parent_node = NULL;
    nd->its_next_node = NULL;
    nd->leaf_or_not= true;

    return nd;
}

node_structure *find_leaf (node_structure *temp_root, string taken_word, int *counter)
{
    int s=0;

    while(temp_root->leaf_or_not == false)
    {
        int i;
        for(int i=0; i<temp_root->current_node; i++)
        {
            if(taken_word < temp_root->word[i])
                break;
        }

        temp_root = temp_root->point[i];
        s++;
    }

    *counter = s;
    return temp_root;
}

void insert_word_with_pointer(node_structure *taken_parent_node, string taken_word, node_structure *next_node)
{
    int i = taken_parent_node->current_node - 1;

    for(;i>=0;i--)
    {
        if(taken_parent_node->word[i] <= taken_word)
            break;
        else
        {
            taken_parent_node->word[i+1] = taken_parent_node->word[i];
            taken_parent_node->point[i+2] = taken_parent_node->point[i+1];
        }
    }

    taken_parent_node->word[i+1] = taken_word;
    taken_parent_node->point[i+2] = next_node;
    taken_parent_node->current_node++;
}

void insert_in_middle_tree(node_structure *taken_parent_node, string taken_word, node_structure *previous_node, node_structure *next_node)
{

    if(taken_parent_node == NULL)
    {
        taken_parent_node = create_new_node();

        taken_parent_node->word[0] = taken_word;
        taken_parent_node->point[0] = previous_node;
        taken_parent_node->point[1] = next_node;
        taken_parent_node->leaf_or_not = false;
        taken_parent_node->current_node++;
        root_node = taken_parent_node;
        previous_node->parent_node = taken_parent_node;
        next_node->parent_node = taken_parent_node;

        return;
    }

    next_node->parent_node = taken_parent_node;
    insert_word_with_pointer(taken_parent_node,taken_word,next_node);

    if(taken_parent_node->current_node == mx)
    {
        node_structure *split_node = create_new_node();
        split_node->leaf_or_not = false;
        int j=0;
        for(int i = taken_parent_node->current_node-(n)/2; i<mx; i++)
        {
            split_node->word[j] = taken_parent_node->word[i];

            if(j==0)
            {
                split_node->point[0] = taken_parent_node->point[i];
                split_node->point[0]->parent_node = split_node;
            }

            split_node->point[j+1] = taken_parent_node->point[i+i];
            split_node->point[j+1]->parent_node = split_node;
            j++;
        }

        taken_parent_node->current_node -=(n)/2+1;
        split_node->current_node = (n)/2;
        insert_in_middle_tree(taken_parent_node->parent_node, taken_parent_node->word[taken_parent_node->current_node], taken_parent_node, split_node );

    }
}

void insert_leaf(string taken_word, string taken_meaning)
{
    int counter = 0;
    node_structure *leaf_node = find_leaf(root_node,taken_word,&counter);

    int i= leaf_node->current_node-1;

    if(i > -1)
    {
        for(; i>=0; i--)
        {
            if(taken_word < leaf_node->word[i])
            {
                leaf_node->word[i+1] = leaf_node->word[i];
                leaf_node->meaning[i+1] = leaf_node->meaning[i];
            }
            else
                break;
        }
    }

    leaf_node->word[i+1] = taken_word;
    leaf_node->meaning[i+1] = taken_meaning;
    leaf_node->current_node++;

    if(leaf_node->current_node == mx)
    {
        node_structure *split_node = create_new_node();
        int j=0;

        for(int i=leaf_node->current_node-n/2; i<mx; i++)
        {
            split_node->word[j] = leaf_node->word[i];
            split_node->meaning[j] = leaf_node->meaning[i];
            j++;
        }

        leaf_node->current_node -=n/2;
        split_node->current_node = n/2;
        split_node->its_next_node = leaf_node->its_next_node;
        leaf_node->its_next_node = split_node;

        insert_in_middle_tree(leaf_node->parent_node, split_node->word[0], leaf_node, split_node);
    }
}

int main(void)
{
	cout << "Number of Child:" << endl;
	cin >> n;
	mx=n;


    root_node = create_new_node();

    node_structure *leaf;
    int i=0,counter;
    string word,meaning,searchEnglish;

    ifstream ifile;
    ifile.open("dictionary.txt");
    if(!ifile)
    {
        cout<<"ERROR";
    }
    while(ifile>>word)
    {

    	getline(ifile,meaning);
    	insert_leaf(word,meaning);
    }


    cout<<"Enter English Word: ";
    while(cin>>searchEnglish)
    {
        auto start = high_resolution_clock::now();

    	 leaf= find_leaf(root_node,searchEnglish,&counter);
    	 for(i=0; i<leaf->current_node; i++)
            if(searchEnglish==leaf->word[i])
                break;

    	 if(i==leaf->current_node)
            cout<<"NO SUCH WORRD\n";
    	 else
            cout<<searchEnglish<<" "<<leaf->meaning[i]<<endl;

         auto stop = high_resolution_clock::now();
         auto duration = duration_cast<microseconds>(stop - start);

	     cout << "SEARCH TIME: "<< duration.count()<< " MICRO SEC. and \nSEACHED STEP: "<<counter<<endl<<endl;
    	 cout<<"Enter English Word: ";
    }


}

