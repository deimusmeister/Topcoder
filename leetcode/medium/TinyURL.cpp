// https://leetcode.com/problems/encode-and-decode-tinyurl/
// 
// TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.
// 
// Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(us.find(longUrl) == us.end()) {
            int n = cur.length();
            if(cur[n - 1] == 'z') {
                cur += "a";
            } else {
                ++cur[n - 1];
            }
            us[longUrl] = cur;
            su[cur] = longUrl;
            return cur;
        } else {
            return us[longUrl];
        }
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return su[shortUrl];
    }
private:
    std::unordered_map<std::string, std::string> us;
    std::unordered_map<std::string, std::string> su;
    std::string cur{"a"};
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
