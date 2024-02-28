#pragma once

#include "Parser/Parser.h"
#include "AssemblerCore.h"

#include <iostream>
#include <string>

#include <fmt/format.h>
#include <fmt/color.h>

namespace Assemble {
	void Assemble(const std::string path) {
		Parser ps{};
		ps.LoadFromFile(path);
		if (!ps.Parse(true)) std::cout << "=> The parsing process has been aborted. There might be more errors.\n";
		else {
			if (!ps.Parse(false)) std::cout << "=> The parsing process has been aborted. There might be more errors.\n";
			else {
				Assembler as{};
				if (!as.AssembleFromTree(ps.getTree())) std::cout << "=> The assembly process has been aborted.\n";
				else {
					fmt::print(fg(fmt::color::green), "=> Successfully assembled binaries for {}\n", path);
					return;
				}
			}
		}
	}
}