#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

enum class term_t {c, var, op, fun, clbr, opbr};

struct term {
	std::string name;
	term_t type;
};

std::vector<term> parse_expression_to_terms(const std::string& expr) {
	std::vector<term> res;
	auto cur = expr.begin();
	while (cur != expr.end()) {
		if (std::isspace(*cur)) {
			++cur;
			continue;
		}
		auto last = std::find_if(cur, expr.end(), [](auto c) {
			return !std::isalnum(c) && c != '.' && c != '_';
			});
		if (cur == last) {
			++last;
		}
		res.push_back({ std::string(cur, last), term_t::op });
		cur = last;
	}
	for (size_t i = 0; i < res.size(); i++) {
		char c = res[i].name[0];
		if (std::isdigit(c) || c == '.') {
			res[i].type = term_t::c;
		}
		else if (c == '(') {
			res[i].type = term_t::opbr;
		}
		else if (c == ')') {
			res[i].type = term_t::clbr;
		}
		else if (std::isalpha(c) || c == '_' && i + 1 < res.size() && res[i + 1].name == "(") {
			res[i].type = term_t::fun;
		}
		else if (std::isalpha(c) || c == '_') {
			res[i].type = term_t::var;
		}
	}

	return res;
}

int main() {

	std::string expr = "3.15*abc - 2^sin(x-y/_z*foo1(abc))";
	auto terms = parse_expression_to_terms(expr);

	for (auto t : terms) {
		std::cout << t.name << " " << (int)t.type << std::endl;
	}
	return 0;
}