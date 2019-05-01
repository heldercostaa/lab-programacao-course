//
//  main.cpp
//  class-01
//
//  Created by Helder Costa (github: heldercostaa) on 30/04/19.
//  Copyright © 2019. All rights reserved.
//

#include <iostream>
#include <tuple>

using namespace std;

tuple<int*, int*> proximosDois(int* p) {
    return make_tuple(p+1, p+2);
}

int main() {
    int v[3] = {1, 2, 3};
    auto elementos = proximosDois(v);
    
    cout << *(get<0>(elementos)) << endl;
    cout << *(get<1>(elementos)) << endl;
}
