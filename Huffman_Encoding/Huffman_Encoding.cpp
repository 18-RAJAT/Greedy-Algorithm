#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    int frequency;
    Node* left,*right;

    //Constructor
    Node(char d,int f,Node* l=nullptr,Node* r=nullptr)
    {
        data=d;
        frequency=f;
        left=l;
        right=r;
    }
};

class compare
{
    public:
    bool operator()(Node*a,Node* b)
    {
        return(a->frequency>b->frequency);
    }
};

void PrintCode(Node* node,string str)
{
        if(node != nullptr)
        {
            if(node->data != '*')

               cout<<node->data<<":"<<str<<"\n";
               PrintCode(node->left,str+'0');
               PrintCode(node->right,str+'1');
        }
}

void cleanup(Node* node)
{
    //Recurse till all the elements are exhausted
    if(node!=nullptr)
    {
        cleanup(node->left);
        cleanup(node->right);

        delete node;
    }
}

void huffmanEncode(char* arr,int* frequency,size_t n)
{
    Node* left,*right,*top;
    priority_queue<Node*,vector<Node*>,compare>q;

    //First fill the priority queue with data
    for(size_t i=0;i<n;++i)
    {
        q.push(new Node(arr[i], frequency[i]));
    }
    //Now extract the minimum element,combine them and reinsert again
    for(size_t i=1;i<n;++i)
    {
        left=q.top();q.pop();
        right=q.top();q.pop();

        // '*' acts as a dummy character
        top=new Node('*',left->frequency+right->frequency,left,right);
        q.push(top);
    }
    PrintCode(q.top(),"");
    
    //Now free up the HEAP space
    cleanup(q.top());

}

int main()
{
    char arr[]={'a','b','c','d','e','f'};
    int  frequency[]={5,9,12,13,16,45};

    huffmanEncode(arr,frequency,sizeof(arr));
    return 0;
}