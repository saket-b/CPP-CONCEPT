#include<iostream>

using namespace std;

struct  Student
{
    char *name;
    int id;

    Student(const char *name1, int id)
    {
        int n = strlen(name)+1;
        name = new char[n];
        strcpy(name, name1);
        name[n]='\0';
    }
};

class Record{

        public:

        void AddRecord(const char* name, int id )
        {
            ls.emplace_back(new Student(name, 10));
            
        }

        bool RemoveRecord(int id)
        {
            int n = ls.size();
            bool flag = false;
            for( int i=0; i<n; i++)
            {
                if( ls[i]->id == id)
                {
                    ls.erase(ls.begin()+i);
                    flag = true;
                    break;
                }

            }
            return flag;

        }

        void Clean(){

            ls.clear();
        }

        void print(){

            int n = ls.size();
            for( int i=0; i<n; i++)
            {
                cout<<ls[i]->name<<" "<<ls[i]->id<<endl;
            }

        }


        private:

        vector<Student*>ls;


};

int main(){

    Record ele;
    ele.print();

    ele.AddRecord("ram", 10);
    ele.AddRecord("shyam", 20);
    ele.AddRecord("sita", 30);
    ele.RemoveRecord(10);
    ele.print();
    ele.Clean();
    ele.print();
    
}
