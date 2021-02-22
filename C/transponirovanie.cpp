//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<vector<int>> F(vector<vector<int>> mas1) {
//    int A = mas1.size();
//    int B = mas1[0].size();
//    vector<vector<int> > mas2(B, vector <int>(A));
//    for (int i = 0; i < A; i++)
//        for (int j = 0; j < B; j++)
//            mas2[j][i] = mas1[i][j];
//    return mas2;
//}
//void Input(vector<vector<int>>& mas1) {
//    int A = mas1.size();
//    int B = mas1[0].size();
//    cout << "Vvedite massiv [" << A << ", " << B << "]";
//    for (int i = 0; i < A; i++)
//        for (int j = 0; j < B; j++)
//            cin >> mas1[i][j];
//}
//void Output(vector<vector<int>> mas2) {
//    int A = mas2.size();
//    int B = mas2[0].size();
//    for (int i = 0; i < A; i++) {
//        for (int j = 0; j < B; j++)
//            cout << mas2[i][j];
//        cout << endl;
//    }
//}
//
//int main() {
//    int A, B;
//    cout << "A = ";
//    cin >> A;
//    cout << "B = ";
//    cin >> B;
//    vector<vector<int> > mas1(A, vector <int>(B));
//    Input(mas1);
//    vector<vector<int>> mas2 = F(mas1);
//    Output(mas2);
//    return 0;
//}