 #include <iostream>
 #include <vector>
using namespace std;

template <class T>
T sorting(vector <T> & a){
    for(int i=1;i<a.size();i++){
        for(int j=0;j<a.size()-i;j++){
            if(a[j]>a[j+1]){
                T tempt =a[j];
                a[j]=a[j+1];
                a[j+1]=tempt;
            }
        }
    }
}


int main(){
   int length,type;
   while(1){
       cin>>length>>type;
       if(length==0)break;

       if(type==0){
           vector <char> input(length);
           for(int i=0;i<length;i++)
           cin>>input[i];

           sorting(input);

           for(int i=0;i<length;i++){
               cout<<input[i];
               if(i<length-1)
               cout<<" ";
           }
           cout<<endl;
       }
       else if(type==1){
           vector <int> input(length);
           for(int i=0;i<length;i++)
           cin>>input[i];

           sorting(input);

           for(int i=0;i<length;i++){
               cout<<input[i];
               if(i<length-1)
               cout<<" ";
           }
           cout<<endl;
       }
       else{
           vector <double> input(length);
           for(int i=0;i<length;i++)
           cin>>input[i];

           sorting(input);

           for(int i=0;i<length;i++){
               cout<<input[i];
               if(i<length-1)
               cout<<" ";
           }
           cout<<endl;
       }
   }
    return 0;

}
