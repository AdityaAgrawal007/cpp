#include <iostream>
using namespace std;

// including gaurds, seperating into headers and .cpp, headers are 
// .h and .hpp, .hpp being specifically for cpp cannot use in c but .h can be used in both, for a project with a mix of both langs .h only can cause ambiguities
// used to avoid naming conflicts in big projects

// namespace nmpsc{
// 	int y = 20;
// 	void cout(int x){
// 	cout << x;}
// }

namespace not_your_std_nmspc{
	int x = 10; 
}

// nested namespaces
namespace outer{
	int o = 1;
	namespace inner{
		int i = 2;
	}
}

// this is not the best thing to use "using" cause it's like removing the safety that namespace put in  
// using namespace nmpsc;

int main(){
	cout << not_your_std_nmspc::x << endl;
	// cout << y << endl;
	cout << outer::o << outer::inner::i << endl;	
}
