#include <iostream>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

int main(){

    /*
    배열에서 가장 긴 증가하는 부분 수열의 길이
    맵을 사용해서, 현재 정한 숫자보다 작은 숫자가 나오면, 키를 추가함.
    30이 처음있었고 쭉쭉 증가하다가, 20이 나왔다 => 그러면 현재 숫자는 20이 되고 키에 20이 추가됨. 
    이러면 증가하는걸 세야하기 때문에 이후 주어지는 숫자는 20과 비교하고 또 다시 30과 비교해야하긴함.
    
    키: 수열의 가장 작은 숫자, 값: 수열에서 가장 큰 숫자

    배열도 하나필요함 수열의 크기 관리 걍 pair로 쓸까
    map<int, pair<int, int>> <수열의 가장 작은 숫자, pair<수열에서 가장 큰 숫자, 수열의 길이>>

    */

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, current_minimum, temp;

    map<int, pair<int, int>> longest_increment_sequence;

    cin >> N >> current_minimum;
    longest_increment_sequence.insert({current_minimum, {current_minimum, 1}});

    for(int i = 1; i < N; i++){
        cin >> temp;

        if(temp < current_minimum) {
            //입력받은 값이 현재 최소값 보다 작을 경우 -> 키값에 추가 하는 과정.
            longest_increment_sequence.insert({temp, {temp, 1}});
            current_minimum = temp;
        }
        else {
            //그 외의 경우 키 배열을 통해 비교과정을 거쳐 +1하는 과정이 필요함.

            for (auto& p : longest_increment_sequence){
                if (temp > p.first && temp > p.second.first) {
                    p.second.second++;
                    p.second.first = temp;
                }
                else if(temp > p.first && temp < p.second.first){
                    p.second.first = temp;
                }
                else break;
            }
        }

    }

    int length = 0;

    for(const auto& p : longest_increment_sequence){
        length = (length > p.second.second) ? length : p.second.second;
    }

    cout << length << endl;

}