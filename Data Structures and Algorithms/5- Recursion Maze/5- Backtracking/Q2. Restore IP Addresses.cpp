class Solution {
public:
	bool check(const string& ip) {
		string cur = "";
		for (auto &it : ip) {
			if (it == '.') {
				if (cur.empty())return false;
				if (cur.size() > 1)
					if (cur[0] == '0')return false;
				if (cur.size() > 3)return false;
				if (stoi(cur) > 255)return false;
				cur = "";
			} else {
				cur += it;
			}
		}
		if (cur.empty())return false;
		if (cur.size() > 1)
			if (cur[0] == '0')return false;
		if (cur.size() > 3)return false;
		if (stoi(cur) > 255)return false;
		cur = "";
		return true;
	}

	vector<string>ans;

	void bruteForce(int i, const string& s, string ip, int cnt = 3) {
		if (cnt < 0)return;
		if (i == s.size()) {
			if (cnt) return;
			if (check(ip)) ans.push_back(ip);
			return;
		}

		bruteForce(i + 1, s, ip + s[i], cnt);

		ip += '.';
		bruteForce(i, s, ip, cnt - 1);
		ip.pop_back();

	}

	vector<string> restoreIpAddresses(string s) {
		ans.clear();
		bruteForce(0, s, "");
		return ans;
	}
};