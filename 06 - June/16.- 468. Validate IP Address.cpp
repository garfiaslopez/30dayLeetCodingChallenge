// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/validate-ip-address/
//
// © Jose Garfias Lopez
//


class Solution {
public:
    
    vector<string> split(string s, char delimiter) {
        // split for only one char.
        /*
        vector<string> splitted;
        string token;
        stringstream ss(s);
        while(getline(ss,token, delimiter)) {
            splitted.push_back(token);
        }
        */
            
        // split for a string or char.
        // string stringDelimiter = string(delimiter);
        vector<string> splitted;
        int current, prev = 0;
        current = s.find(delimiter);
        while(current != -1) {
            splitted.push_back(s.substr(prev, current - prev));
            prev = current + 1;
            current = s.find(delimiter, prev);
        }
        splitted.push_back(s.substr(prev, current - prev));
        
        return splitted;
    }
    
    int countZerosFromLeft(string s) {
        int zeros = 0;
        for (char c: s) {
            if (c == '0') { 
                zeros++;
            } else {
                break;
            }
        }
        return zeros;
    }
    bool onlyDigits(string s) {
        for (char c: s) {
            if (!isdigit(c)) return false;
        }
        return true;
    }
    
    bool isValidIpv4(string ip) {
        vector<string> numbers = split(ip, '.');
        if (numbers.size() != 4) return false;
        for (string number : numbers) {
            if (number.length() == 0 || number.length() > 3) return false;
            if (!onlyDigits(number)) return false;
            
            int n = stoi(number);
            if (number.length() > 1 && countZerosFromLeft(number) > 0) return false;
            if (n > 255) return false;
        }
        return true;
    }
    
    bool onlyXDigits(string s) {
        for (char c: s) {
            if (!isxdigit(c)) return false;
        }
        return true;
    }
    
    bool isValidIpv6(string ip) {
        vector<string> numbers = split(ip, ':');
        if (numbers.size() != 8) return false;
        for (string number : numbers) {
            if (number.length() == 0 || number.length() > 4) return false;
            if (!onlyXDigits(number)) return false;
        }
        return true;
    }
    
    string validIPAddress(string IP) {
                                
        if (isValidIpv6(IP)) {
            return "IPv6";
        }
        if (isValidIpv4(IP)) {
            return "IPv4";
        }

        return "Neither";
    }
    
    
};