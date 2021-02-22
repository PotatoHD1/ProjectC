//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//    int month = 0;
//
//    const vector<int> days_in_month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//    vector<vector<string>> affairs(days_in_month[month]);
//
//    int count_of_commands;
//
//    cin >> count_of_commands;
//
//    for (int i = 0; i < count_of_commands; i++)
//    {
//        string command;
//
//        cin >> command;
//
//        if (command == "ADD")
//        {
//            int day;
//            string task;
//            cin >> day >> task;
//            affairs[day - 1].push_back(task);
//        }
//        else if (command == "NEXT")
//        {
//            vector<vector<string>> buff = affairs;
//            if (++month > 11)
//                month = 0;
//
//            affairs.resize(days_in_month[month]);
//
//            if (affairs.size() < buff.size())
//            {
//                for (int i = affairs.size(); i < buff.size(); i++)
//                {
//                    affairs[affairs.size() - 1].insert(end(affairs[affairs.size() - 1]), begin(buff[i]), end(buff[i]));
//                }
//            }
//        }
//        else if (command == "DUMP")
//        {
//            int day;
//            cin >> day;
//            cout << affairs[day - 1].size() << " ";
//        	for (int i = 0; i < affairs[day-1].size();i++)
//                cout << affairs[day-1][i] << " ";
//            for (string s : affairs[day - 1])
//                cout << s << " ";
//            cout << endl;
//        }
//    }
//}