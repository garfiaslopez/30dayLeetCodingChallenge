// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/evaluate-division/
//
// © Jose Garfias Lopez
//

//https://leetcode.com/problems/evaluate-division/discuss/439613/C%2B%2B-DFS-100-time-99-memory-with-explanation-%2B-comments

class Solution {
public:
	struct Node {
		Node(string v, double r) {
			this->variable = v;
			this->result = r;
		}
		string variable;
		double result;
	};

	map<string, vector<Node>> graph;
	void buildGraph(vector<vector<string>>& equations, vector<double>& values) {
		for(auto& e: equations) {
			vector<Node> children;
			graph[e[0]] = children; /* init each node */
		}

		for(int e = 0; e < equations.size(); ++e) {
			Node n(equations[e][1], values[e]);
			graph[equations[e][0]].push_back(n);

			/* add the inverse of the equation to the graph as well */
			Node n_inverse(equations[e][0], 1/values[e]);
			graph[equations[e][1]].push_back(n_inverse);
		}
	}

	bool solveEquation(string top, string bottom, double& accum, set<string>& visited) {
		if(top == bottom && graph.find(top) != graph.end()) {
			return true;
		}

		/* if either top or bottom aren't in the graph, then the equation is unsolvable */
		if(graph.find(top) == graph.end() || graph.find(bottom) == graph.end()) {
			return false;
		}

		visited.insert(top);
		for(auto& child : graph[top]) {
			/* only recurse if the child has never been seen before */
			if(visited.find(child.variable) == visited.end()) {
				accum *= child.result;  /* temporarily do the multiplication */
				if(child.variable == bottom) {
					return true;
				}
				/* if somewhere down the tree we encounter the result, then propogate that all the way back up the tree */
				if(solveEquation(child.variable, bottom, accum, visited)) {
					return true;
				} else {
					accum /= child.result;  /* if the current path down the tree yielded a false result, undo the multiplication */
				}
			}
		}
		return false;  /* can't find a solution */
	}

	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		buildGraph(equations, values);
		vector<double> results;
		for(auto& q : queries) {
			set<string> visited;
			double accum = 1.0;

			bool res = solveEquation(q[0], q[1], accum, visited);
			if(res) {
				results.push_back(accum);   
			} else {
				results.push_back(-1.0);
			}
		}
		return results;
	}
};