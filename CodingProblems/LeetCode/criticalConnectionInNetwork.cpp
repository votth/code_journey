/*
There are 'n' servers numbered from 0 to n-1 connected by undirected server-to-server 'connections forming a network where 'connection[i]=[ai,bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
A critical connection is a connection that, if removed will make some servers unable to reach some others.
Return all critical connection in the network in any order.

https://leetcode.com/problems/critical-connections-in-a-network/

Constraints:
	2 <= n <= 10^5
	n-1 <= connections.length <= 10^5
	0 <= ai, bi <= n-1
	ai != bi
	There are no repeated connections

Recap:
	n nodes, index 0 to n-1
	connections containers of edges (nodes pairing)
	Find nodes where sub-trees are connected
*/

class Solution {
pulic:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
	}
};
