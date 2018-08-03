#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <string>

#define word_lenght  50
using namespace std;

int main(){
	char word[word_lenght];
	int i = 0;
	map<string, int> vacebulary;
	set<int> count;
	set<string> words;
	set<string>::iterator it;
	string path;
	
	ifstream file;
	
	cout<< "Insert a text file dir:";
	cin>>path;
	
	file.open(path);
	
	if(file.is_open()){
		//get the first char in the file
		char c = file.get();
		while (file.good()){
			//checking if it is the white-space or punct
			if(!isspace(c) and !ispunct(c)){
				word[i] = c;
				i++;
				word[i] = '\0';
				}
			else{
				if(word[0] != '\0'){
					//checking if the word in the set
					it = words.find(word);
					if(it == words.end()){
						words.insert(word);
						vacebulary[word]=1;
					}
					else{
						vacebulary[word]+=1;
					}
					i = 0;
					//drop the the previuos word
					for(int j = 0; j < word_lenght; j++){
						word[j]='\0';
					}
				}
			}
			c = file.get();
		}
	}
	else{
		cout << "openning the file was failed" << endl;
	}
	file.close();
	for(auto iter = vacebulary.begin(); iter!=vacebulary.end(); iter++){
		count.insert(iter->second);
	}
	
	cout << "The text contains the next words:" << endl;
	for(auto iter_set = count.rbegin(); iter_set!=count.rend(); iter_set++){
		for(auto iter_map = vacebulary.begin(); iter_map!=vacebulary.end(); iter_map++){
			if(iter_map->second == *iter_set){
				cout << iter_map->second << " => " << iter_map->first << endl;
			}
		}
	}
return 0;
}
