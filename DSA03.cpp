#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
struct dt_node
{
    char caption[100];
    int chapters;
    struct dt_node *cnode[100];
} *root;
class BOOK
{
    public:
    void create_tree();
    void display(dt_node *rl);
    BOOK()
    {
        root=NULL;
    }
};
void BOOK::create_tree()
{
    int chp_cnt,i,j,k;
    root=new dt_node();
    cout<<"ENTER NAME OF BOOK: ";
    cin>>root->caption;
    cout<<"\nENTER NUMBER OF CHAPTERS IN THE BOOK: ";
    cin>>chp_cnt;
    root->chapters=chp_cnt;
    for(i=0;i<chp_cnt;i++)
    {
        root->cnode[i]=new dt_node;
        cout<<"\nEnter Chapter's name:";
        cin>>root->cnode[i]->caption;
        cout<<"\nENTER NUMBER OF SECTIONS IN THE CHAPTER "<<root->cnode[i]->caption<<" ";
        cin>>root->cnode[i]->chapters;
        for(j=0;j<root->cnode[i]->chapters;j++)
        {
            root->cnode[i]->cnode[j]=new dt_node;
            cout<<"\nENTER SECTION "<<j+1<<" name: ";
            cin>>root->cnode[i]->cnode[j]->caption;
        }
    }
}
void BOOK::display(dt_node *rl)
{
    int i,j,k,chp_cnt;
    if(rl!=NULL)
    {
        cout<<"\n-------------BOOK HIERARCHY-------------";
        cout<<"\nBook Title: "<<rl->caption;
        chp_cnt=rl->chapters;
        for(i=0;i<chp_cnt;i++)
        {
            cout<<"\nChapter"<<i+1;
            cout<<" "<<rl->cnode[i]->caption;
            cout<<"\nSections";
            for(j=0;j<rl->cnode[i]->chapters;j++)
            {
                cout<<"\n "<<rl->cnode[i]->cnode[j]->caption;
            }
        }
        cout<<endl;
    }
}
int main()
{
    int choice;
    BOOK BOOK;
    while (1)
    {
        cout<<"-------------------------"<<endl;
        cout<<"Book Tree Creation"<<endl;
        cout<<"1. Create\n2. Display\n3. Quit\n";
        cout<<"Enter youe choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            BOOK.create_tree();
            break;
            case 2:
            BOOK.display(root);
            break;
            case 3:
            exit(1);
            default:
            cout<<"Wrong choice"<<endl;
        }
    }
}
