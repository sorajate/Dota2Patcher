#pragma once
#include <Windows.h>
#include <iostream>

namespace Paths {
	bool get_dota_path_from_reg(std::string* path);
	bool get_dota_path(std::string* path);
}

namespace Patcher {
	void DrawMenu();
	void SwitchCommand(int USER_INPUT);
	void CheckUpdate();
	int find_offset(char* array, int array_length, BYTE* pattern, int pattern_length);
	int find_offset(std::string file_path, BYTE* pattern, int pattern_size);
	bool get_byte_array(std::string file_path, char** ret_array, int* file_size);
	void apply_patch(std::string file_path, int patch_offset, BYTE replace[], int bytes_to_replace);

	bool patch_dota_plus(bool revert);
	bool patch_gameinfo(bool revert);
	bool patch_sv_cheats(bool revert);
}

namespace Globals {
	inline std::string local_version = "3.0.5.2";
	inline std::string dota_path;

	inline BYTE dota_plus_pattern[] = { 0xBF, 0x00, 0x00, 0x00, 0x00, 0x8B, 0x48, 0x58, 0x85, 0xC9, 0x0F, 0x85 };
	inline BYTE sv_cheats_pattern[] = { 0x74, 0x00, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x84, 0xC0, 0x75, 0x00, 0xE8 };
	inline BYTE gameinfo_pattern[] = { 0x74, 0x00, 0x44, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x00, 0x83, 0xBF };
}
