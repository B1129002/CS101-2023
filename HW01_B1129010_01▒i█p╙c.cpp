#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int x, y;
    cout << "x個字串:";
    cin >> x;
    cout << "長度y:";
    cin >> y;

    // 2D array
    char **str;
    str = (char **)malloc(x * sizeof(char *));
    for (int i=0; i<x; i++) {
        str[i] = (char*)malloc((y + 1) * sizeof(char));
    }

    // input string
    for (int i = 0; i < x; i++) {
        str[i][y] = '\0';
        cout << "input" << i + 1 << endl;
        cin >> str[i];
        if (str[i][y] != '\0') {
            cout << "input again" << endl;
            cout << i << endl;
            for (int j = 0; j <= y; j++) {
                str[i][j] = '\0';
            }
            i--;
        }
    }

    // bubblesort 
    for(int i=0; i<x; i++){
        for(int j=0; j<x; j++){
            if(**(str+i) > **(str+j)){
                for (int k=0; k<y; k++){
                    int tmp = *(*(str+i)+k);
                    *(*(str+i)+k) = *(*(str+j)+k);
                    *(*(str+j)+k) = tmp;
                }
            }
        }
    }

    // output string
    cout << "Output:" << endl;
    for (int i = 0; i < x; i++) {
        cout << str[i] << endl;
    }

    // free memory
    for (int i = 0; i < x; i++) {
        free(str[i]);
    }
    free(str);

    return 0;
}
