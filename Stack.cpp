#include<iostream>
using namespace std;
#define CAPACITY 50

class stack{
private:
  int stack_arr[CAPACITY];
  int top = -1;
  int size;
public:
  int isFull(){
    if(top == CAPACITY){
      return true;
    }else{
      return false;
    }
  }
  int isEmpty(){
    if(top == -1){
      return true;
    }else{
      return false;
    }
  }
  void push() {
    if(isFull()){
      cout<<"STACK IS OVERFLOW"<<endl;
    }else{
      top++;
      int n;
      cout<<"ENTER YOUR ELEMENT:";
      cin>>n;
      stack_arr[top] = n;
      cout<<"ELEMENT "<<n<<" IS INSERTED"<<endl;
    }
  }
  void pop(){
    if(isEmpty()){
      cout<<"STACK IS UNDERFLOW"<<endl;
    }else{
      cout<<stack_arr[top]<<endl;
      top--;
    }
  }
  int length(){
    size = 0;
    for(int i=0;i<=top;i++){
      size++;
    }
    return size;
  }
  void display(){
    cout<<"ELEMENTS OF THE STACK: ";
    for(int i=0; i<length(); i++){
      cout<<stack_arr[i];
    }
    cout<<endl;
  }
};

int main(){
  int no_of_stacks;
  cout<<"ENTER HOW MANY STACKS ARE REQUIRED:";
  cin>>no_of_stacks;
  cout<<endl;
  stack s[no_of_stacks];
  for(int i = 0; i < no_of_stacks; i++){
    bool start = true;
    int opt;
    while(start){
      int nth_stack;
      int sub_opt;
      cout<<"STACK "<<i+1<<" OPERATIONS:"<<endl;
      cout<<"1.PUSH AN ELEMENT"<<endl;
      cout<<"2.POP AN ELEMENT"<<endl;
      cout<<"3.LENGTH OF THE STACK ARRAY"<<endl;
      cout<<"4.DISPLAY ELEMENTS OF THE ARRAY"<<endl;
      cout<<"5.GET THE DETAILS OF ANOTHER STACK"<<endl;
      cout<<"6.READ ANOTHER STACK OR STOP"<<endl;
      cout<<"-----------------------------------------"<<endl;
      cout<<"ENTER YOUR OPTION:";
      cin>>opt;
      cout<<"-----------------------------------------"<<endl;

      switch (opt) {
        case 1:s[i].push();
               break;
        case 2:s[i].pop();
               break;
        case 3:cout<<"SIZE OF THE STACK ARRAY IS:"<<s[i].length()<<endl;
               break;
        case 4:s[i].display();
               break;
        case 5:cout<<"PLEASE ENTER nth STACK:";
               cin>>nth_stack;
               if(nth_stack>no_of_stacks || nth_stack<0){
                 cout<<"STACK IS NOT PRESENT"<<endl;
               }else{
                 cout<<"STACK "<<nth_stack<<" OPERATIONS:"<<endl;
                 cout<<"1.PUSH AN ELEMENT"<<endl;
                 cout<<"2.POP AN ELEMENT"<<endl;
                 cout<<"3.LENGTH OF THE STACK ARRAY"<<endl;
                 cout<<"ENTER YOUR OPTION:";
                 cin>>sub_opt;
                 cout<<"-----------------------------------------"<<endl;
                 switch (sub_opt) {
                   case 1:s[nth_stack-1].push();
                          break;
                   case 2:s[nth_stack-1].pop();
                          break;
                   case 3:cout<<"SIZE OF THE STACK ARRAY IS:"<<s[nth_stack-1].length()<<endl;
                         break;
                   default:cout<<"WRONG OPTION"<<endl;
                 }
               }
               break;
        case 6:start=false;
               break;
        default:cout<<"INCORRECT OPTION"<<endl;
      }
      cout<<"-----------------------------------------"<<endl;
    }
  }
}
