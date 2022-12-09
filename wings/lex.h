#pragma once
#include "common.h"

#include <vector>
#include <string>

namespace wings {
	struct Token {
		enum class Type {
			Null,
			Bool,
			Int,
			Float,
			String,
			Symbol,
			Word,
			Keyword,
		} type;

		std::string text;
		SourcePosition srcPos;

		struct {
			union {
				bool b;
				Wg_int i;
				Wg_float f;
			};
			std::string s;
		} literal;

		std::string ToString() const;
	};

	struct LexTree {
		std::vector<Token> tokens;
		std::vector<LexTree> children;
	};

	struct LexResult {
		std::vector<std::string> originalSource;
		LexTree lexTree; // Root tree contains no tokens
		CodeError error;
	};

	LexResult Lex(std::string code);
}
