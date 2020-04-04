#include<iostream>

using namespace std;

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};

// MUST COPY THE ENTIRE class D TO RUN IT PROPERLY IN HACKER RANK

class D : public A, public B, public C
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val = 1;
		 }


		 //Implement this function
		 void update_val(int new_val)
		 {
            int copy = new_val;

            while(copy%2 == 0)
            {
                copy = copy / 2;
                // A::func(val) is the same as this->A::func(val)
                A::func(val);
            }

            while(copy%3 == 0)
            {
                copy = copy / 3;
                B::func(val);
            }

            while(copy%5 == 0)
            {
                copy = copy / 5;
                C::func(val);
            }
			
		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};

void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cout << "Input (Must have factors of only 2, 3 and 5): " << endl;
    cin >> new_val;
    d.check(new_val);

    return 0;

}