// C++ program of the above approach
#include <bits/stdc++.h>
using namespace std;
class Compare
{
public:
    bool operator() (const pair<int,int> a, const pair<int,int> b)
    {
        if(a.first==b.first) return a.second<b.second;
    }
};
// Function which returns
// the largest possible string
string lexicographicallyLargest(string S, int K)
{
	// Finding length of the string
	int n = S.length();

	// Creating two priority queues of pairs
	// for odd and even indices separately
	priority_queue<pair<char, int> > pq;

	// Storing all possible even
	// indexed values as pairs
	for (int i = 2; i < n; i = i + 2) {
		// Stores pair as {character, index}
		pq.push(make_pair(S[i], i));
	}

	// Storing all possible odd indexed
	// values as pairs
	for (int i = 3; i < n; i = i + 2) {
		// Stores pair as {character, index}
		pq.push(make_pair(S[i], i));
	}

	for (int i = 0; i < n; i++) {

			// Removing pairs which
			// cannot be used further
			while (!pq.empty()
				and pq.top().second <= i)
				pq.pop();

			// If a pair is found whose index comes after
			// the current index and its character is
			// greater than the current character
			if (!pq.empty()
				and pq.top().first > S[i]) {

				// Swap the current index with index of
				// maximum found character next to it
				swap(S[i], S[pq.top().second]);

				int idx = pq.top().second;
				pq.pop();
				// Push the updated character at idx index
				pq.push({ S[idx], idx });
				K--;
			}
		
		// Breaking out of the loop if K=0
		if (K == 0)
			break;
	}

	return S;
}

// Driver Code
int main()
{
	// Input
	 string s;int k;
	 cin>>s>>k;
	// Function Call
	cout << lexicographicallyLargest(s, k);
	return 0;
}
