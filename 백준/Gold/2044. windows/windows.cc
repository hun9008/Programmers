#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

vector< pair<string, pair<int, int> > > v;
string windows[101];
bool visited[101][101];
int win[101][101];
int n, m;
int x = 0;
int y = 0;

void windowInfo(int i, int j){
    int width = 1;
    int height = 1;
    string word = "";
    while(windows[i][j + width] - '+' != 0){
        if(97 <= windows[i][j + width] && windows[i][j + width] <= 122) {
            word += windows[i][j + width];
        }
        width++;
    }
    width++;

    while(windows[i + height][j] - '+' != 0){
        height++;
    }
    height++;
    v.push_back(make_pair(word, make_pair(width, height)));
    visited[i][j] = true;
    visited[i+height-1][j] = true;
    visited[i][j+width-1] = true;
    visited[i+height-1][j+width-1] = true;
    
}

void printWindow() {
    // 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(win[i][j] == 0){
                printf(".");
            } else if(win[i][j] == 1){
                printf("+");
            } else if(win[i][j] == 2){
                printf("-");
            } else if(win[i][j] == 3){
                printf("|");
            } else{
                printf("%c", win[i][j]);
            }
        }
        printf("\n");
    }
    return;
}

// width - string.len() - 4
void setWindow(vector< pair<string, pair<int, int> > > wnd, int idx){

    int width = wnd[idx].second.first;
    int height = wnd[idx].second.second;
    int minus = width - wnd[idx].first.size() - 4;
    int half = minus / 2;

    win[x][y] = 1;
    win[x][y + width - 1] = 1;
    for(int mi = 1; mi <= half; mi++)
    {
        win[x][y + mi] = 2;
    }
    win[x][y + half + 1] = 3;
    int startS = y + half + 2;
    for(int i = 0; i < static_cast<int>(wnd[idx].first.size()); i++)
    {
        win[x][startS + i] = wnd[idx].first[i];
    }
    startS += wnd[idx].first.size();
    win[x][startS] = 3;
    // startS++;
    if(minus % 2 == 0){
        for(int mi = 1; mi <= half; mi++)
        {
            win[x][startS + mi] = 2;
        }
    } else{
        for(int mi = 1; mi <= half + 1; mi++)
        {
            win[x][startS + mi] = 2;
        }
    }
    int innerH = height - 2;
    int innerW = width - 2;

    for(int h = 0; h < innerH; h++)
    {
        win[x + 1 + h][y] = 3;
        for(int w = 0; w < innerW; w++)
        {
            win[x + 1 + h][y + 1 + w] = 0;
        }
        win[x + 1 + h][y + 1 + innerW] = 3;
    }

    win[x + 1 + innerH][y] = 1;
    win[x + 1 + innerH][y + width - 1] = 1;

    for(int w = 0; w < innerW; w++)
    {
        win[x + 1 + innerH][y + 1 + w] = 2;
    }





    x++;
    y++;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> windows[i];
        memset(visited[i], false, 101);
        memset(win[i], 0, 101);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(windows[i][j] - '+' == 0 && visited[i][j] == false){
                windowInfo(i, j);
                // cout << i << " " << j << endl;
            }
        }
    }

    sort(v.begin(), v.end());

    for(size_t i = 0; i < v.size(); i++)
    {
        // cout << v[i].first << " " << endl;
        setWindow(v, static_cast<int>(i));
    }

    printWindow();


    return 0;
}