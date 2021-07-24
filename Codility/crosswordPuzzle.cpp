/*
A 10*10 Crossword grid is provided to you, along with a set of words (or names of places) which need to be filled into the grid. Cells are marked either + or -. Cells marked with a - are to be filled with the word list.

Input 	   		Output

++++++++++ 		++++++++++
+------+++ 		+POLAND+++
+++-++++++ 		+++H++++++
+++-++++++ 		+++A++++++
+++-----++ 		+++SPAIN++
+++-++-+++ 		+++A++N+++
++++++-+++ 		++++++D+++
++++++-+++ 		++++++I+++
++++++-+++ 		++++++A+++
++++++++++ 		++++++++++
POLAND;LHASA;SPAIN;INDIA
Function Description

Complete the crosswordPuzzle function in the editor below. It should return an array of strings, each representing a row of the finished puzzle.

crosswordPuzzle has the following parameter(s):

crossword: an array of 10 strings of length 10 representing the empty grid
words: a string consisting of semicolon delimited strings to fit into 
Input Format

Each of the first 10 lines represents crossword[i], each of which has 10 characters, crossword[i][j].

The last line contains a string consisting of semicolon delimited word[i] to fit.


*/

vector<string> finalGrid;

void call(int ind, vector<string> grid, vector<string> words)
{   
    if(ind == words.size()) {  
        finalGrid = grid;
        return;
    }
    
    for(int i= 0;i < 10; ++i) {
        for(int j=0; j < 10; ++j) {
            int p = i, q = j, k;
            for(k = 0;k < words[ind].size() && p+k < 10; ++k) {
                if(grid[p+k][q] != '-' && grid[p+k][q] != words[ind][k])
                    break;
            }

            if(k == words[ind].size()) {
                vector<string> temp = grid;
                for(k=0;k<words[ind].size();++k)
                    grid[p+k][q] = words[ind][k];

                call(ind+1, grid, words);
                grid = temp;
            }

            for(k = 0;k < words[ind].size() && q+k < 10; ++k) {
                if(grid[p][q+k] != '-' && grid[p][q+k] != words[ind][k])
                    break;
            }

            if(k == words[ind].size()) {
                vector<string> temp = grid;
                for(k=0; k<words[ind].size(); ++k)
                    grid[p][q+k] = words[ind][k];

                call(ind+1, grid, words);
                grid = temp;
            }
        }
    }
}

vector<string> crosswordPuzzle(vector<string> crossword, string s) {
    string delimiter = ";";

    size_t pos_start = 0, pos_end;
    vector<string> words;
    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        words.push_back(s.substr(pos_start, pos_end - pos_start));
        pos_start = pos_end + 1;
    }

    words.push_back (s.substr(pos_start));
    
    call(0, crossword, words);

    return finalGrid;
}
