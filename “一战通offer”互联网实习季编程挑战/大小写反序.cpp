class Transform {
public:
    bool isUpper(char c){
	if (c >= 'A'&&c <= 'Z')
		return true;
	else return false;
}
char change(char c){
	if (isUpper(c))
		return (char)(c + 'a' - 'A');
	else return (char)(c + 'A' - 'a');
}
vector<string> split(string str,int len){
	vector<string> res;
	string temp="";
	for (int i = 0; i < len; i++){
		if (str[i] != ' ')
			temp += change(str[i]);
		else{
			res.push_back(temp);
			temp = "";
		}
	}
	res.push_back(temp);
	return res;
}
   string trans(string str, int n) {
		vector<string> s = split(str, n);
		string ans = "";
		vector<string>::iterator itr = s.end();
		itr--;
		for (; itr != s.begin(); itr--)
		{
			ans=ans+ *itr + " ";
		}
		ans+= *itr;
		return ans;
	}
};
