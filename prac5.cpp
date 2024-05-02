#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TreeNode{
    public:
        string title;
        vector<TreeNode*>children;
        TreeNode(const string& title):title(title){}

        void addChild(TreeNode* child)
        {
            children.push_back(child);
        }

        static void PrintTree(TreeNode*node, int level=0)
        {
            string indent(level*4,' ');
            string label;
            if (level==0) label="book : ";
            else if (level==1) label="chapter: ";
            else if (level==2) label="section : ";
            else label="subsection : ";

            cout<<indent<<label<<node->title<<endl;
            for(size_t i=0;i<node->children.size();i++)
            {
                PrintTree(node->children[i],level+1);
            }
        }
        ~TreeNode()
        {
            for(size_t i=0;i<children.size();i++)
                delete children[i];
        }
};
int main()
{
    string title;
    int ch,sec,subsec;
    cout<<"Enter the title : ";
    getline(cin,title);
    TreeNode*book= new TreeNode(title);
    cout<<"Enter the number of chapters : ";
    cin>>ch;
    cin.ignore();
    for(int i=0;i<ch;i++)
    {
        cout<<"Enter the title for chapter "<<i+1<<" : ";
        getline(cin,title);
        TreeNode*chapter=new TreeNode(title);

        cout<<"Enter the number of sections : ";
        cin>>sec;
        cin.ignore();
        for(int j=0;j<sec;j++)
        {
            cout<<"Enter the title for section "<<j+1<<" : ";
            getline(cin,title);
            TreeNode*section = new TreeNode(title);

            chapter->addChild(section);
        }
    book->addChild(chapter);
    }
    cout<<"\n Book Structure \n";
    TreeNode :: PrintTree(book);
    delete book;
    return 0;
}

        
        
      
        

