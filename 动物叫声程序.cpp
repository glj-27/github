#include<iostream>
#include<string>
using namespace std;
class Animal
{
    public:
        string voice;
};
class Cat:public Animal
{
        public:
           void sounds();
};
void Cat::sounds()
{
        voice="meow";
        cout<<voice<<endl;
}
class Dog:public Animal
{
        public:
            void sounds();
        
};
void Dog::sounds()
{
        voice="wang";
        cout<<voice<<endl;
}

class Tiger:public Animal
{
        public:
            void sounds();
        
};
void Tiger::sounds()
{
        voice="howl";
        cout<<voice<<endl;
}

int main()
{
        string a;
        while(cin>>a)
        {
                
                if(a=="cat")
                {
                        Cat cat;
                        cat.sounds();
                }
				else if(a=="dog")
                {
                        Dog dog;
                        dog.sounds();
                }
                else if(a=="tiger")
                {
                        Tiger tiger;
                        tiger.sounds();
                }
				else if(a!="cat"||a!="dog"||a!="tiger")
                {
                        break;
                }
        }
        return 0;
}
