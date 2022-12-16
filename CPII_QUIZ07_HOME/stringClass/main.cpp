#include<iostream>
#include<string>
using namespace std;


class textString{
    public:
    explicit textString(std::string name) :text(name){}
    std::string getName(){return text;}
    void setName(std::string name){text=name;}
    int asciiCode(){
        int sum=0;
        for(int i=0;i<text.size();i++)
        sum+=(int)(text.at(i));
        return sum;
    }
    int isEqualTen(int num){
        int sample=num;
        while(sample>=10){
            int sample1=0;
            while(sample>0){
                sample1+=sample%10;
                sample/=10;
            }
            sample=sample1;
        }
        return sample;

    }

    private:
    std::string text;
};

int main(){
    int testCase=500;
    std::string inputString;
    while(testCase--){
    getline (cin,inputString);
    textString input(inputString);
    int ans=input.asciiCode();
    cout<<input.isEqualTen(ans)<<endl;
    return 0;

    }

}
