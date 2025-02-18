/*
 * Gearsystem - Sega Master System / Game Gear Emulator
 * Copyright (C) 2013  Ignacio Sanchez

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/ 
 * 
 */

#ifndef GAME_DB_H
#define	GAME_DB_H

#include "definitions.h"

#define GS_DB_DEFAULT_MAPPER 0
#define GS_DB_CODEMASTERS_MAPPER 1
#define GS_DB_SG1000_MAPPER 2
#define GS_DB_MSX_MAPPER 3
#define GS_DB_KOREAN_MAPPER 4
#define GS_DB_JANGGUN_MAPPER 5
#define GS_DB_KOREAN_MSX_SMS_8000_MAPPER 6
#define GS_DB_KOREAN_SMS_32KB_2000_MAPPER 7
#define GS_DB_KOREAN_MSX_32KB_2000_MAPPER 8
#define GS_DB_KOREAN_2000_XOR_1F_MAPPER 9
#define GS_DB_KOREAN_MSX_8KB_0300_MAPPER 10
#define GS_DB_KOREAN_0000_XOR_FF_MAPPER 11
#define GS_DB_KOREAN_FFFF_HICOM_MAPPER 12
#define GS_DB_KOREAN_FFFE_MAPPER 13
#define GS_DB_KOREAN_BFFC_MAPPER 14
#define GS_DB_KOREAN_FFF3_FFFC_MAPPER 15
#define GS_DB_KOREAN_MD_FFF5_MAPPER 16
#define GS_DB_MULTI_4PAK_ALL_ACTION_MAPPER 17
#define GS_DB_JUMBO_DAHJEE_MAPPER 18

#define GS_DB_FEATURE_NONE 0x00
#define GS_DB_FEATURE_PAL 0x01
#define GS_DB_FEATURE_SMS_MODE 0x02
#define GS_DB_FEATURE_NO_BATTERY 0x04
#define GS_DB_FEATURE_YM2413 0x08
#define GS_DB_FEATURE_INITIAL_VINT 0x10
#define GS_DB_FEATURE_DISABLE_YM2413 0x20
#define GS_DB_FEATURE_FORCE_JAPAN_SMS 0x40
#define GS_DB_FEATURE_PADDLE 0x80

struct GS_GameDBEntry
{
    u32 crc;
    u8 mapper;
    int features;
    const char* title;
};

const GS_GameDBEntry kGameDatabase[] =
{
    // CODEMASTERS MAPPER, PAL TIMING
    {0x29822980, GS_DB_CODEMASTERS_MAPPER, GS_DB_FEATURE_PAL, "Cosmic Spacehead"},
    {0x8813514B, GS_DB_CODEMASTERS_MAPPER, GS_DB_FEATURE_PAL, "Excellent Dizzy Collection [Proto]"},
    {0xB9664AE1, GS_DB_CODEMASTERS_MAPPER, GS_DB_FEATURE_PAL, "Fantastic Dizzy"},
    {0xA577CE46, GS_DB_CODEMASTERS_MAPPER, GS_DB_FEATURE_PAL, "Micro Machines"},
    
    // CODEMASTERS MAPPER, NTSC TIMING, SMS MODE
    {0xC888222B, GS_DB_CODEMASTERS_MAPPER, GS_DB_FEATURE_SMS_MODE, "Fantastic Dizzy [SMS-GG]"},
    {0xAA140C9C, GS_DB_CODEMASTERS_MAPPER, GS_DB_FEATURE_SMS_MODE, "Excellent Dizzy Collection, The [SMS-GG]"},
    {0x76C5BDFB, GS_DB_CODEMASTERS_MAPPER, GS_DB_FEATURE_SMS_MODE, "Jang Pung 2 [SMS-GG]"},

    // CODEMASTERS MAPPER, NTSC TIMING
    {0x72981057, GS_DB_CODEMASTERS_MAPPER, GS_DB_FEATURE_NONE, "CJ Elephant Fugitive"},
    {0x6CAA625B, GS_DB_CODEMASTERS_MAPPER, GS_DB_FEATURE_NONE, "Cosmic Spacehead [GG]"},
    {0xEA5C3A6F, GS_DB_CODEMASTERS_MAPPER, GS_DB_FEATURE_NONE, "Dinobasher - Starring Bignose the Caveman"},
    {0x152F0DCC, GS_DB_CODEMASTERS_MAPPER, GS_DB_FEATURE_NONE, "Dropzone (Archer MacLean's)"},
    {0x5E53C7F7, GS_DB_CODEMASTERS_MAPPER, GS_DB_FEATURE_NO_BATTERY,  "Ernie Els Golf"},
    {0xD9A7F170, GS_DB_CODEMASTERS_MAPPER, GS_DB_FEATURE_NONE, "Man Overboard!"},
    {0xDBE8895C, GS_DB_CODEMASTERS_MAPPER, GS_DB_FEATURE_NONE, "Micro Machines 2: Turbo Tournament"},
    {0xF7C524F6, GS_DB_CODEMASTERS_MAPPER, GS_DB_FEATURE_NONE, "Micro Machines [GG]"},
    {0xC1756BEE, GS_DB_CODEMASTERS_MAPPER, GS_DB_FEATURE_NONE, "Pete Sampras Tennis"},
    
    // PAL
    {0x72420F38, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Addams Family, The"},
    {0x887D9F6B, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Ace of Aces"},
    {0x8B43D21D, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Air Rescue"},
    {0xC8718D40, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Aladdin"},
    {0xB618B144, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Alien 3"},
    {0x7F30F793, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Alien Storm"},
    {0xF499034D, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Andre Agassi Tennis"},
    {0xE4163163, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Arcade Smash Hits"},
    {0x861B6E79, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Assault City (Light Phaser)"},
    {0x0BD8DA96, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Assult City (Joypad)"},
    {0x147E02FA, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Asterix 1.0"},
    {0x8C9D5BE8, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Asterix 1.1"},
    {0xF9B7D26B, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Asterix and the Great Rescue"},
    {0xDEF9B14E, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Asterix and the Secret Mission"},
    {0xE890331D, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Ayrton Senna's Super Monaco GP II"},
    {0xE5FF50D8, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Back to the Future Part II"},
    {0x2D48C1D3, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Back to the Future Part III"},
    {0x655FB1F4, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Bank Panic"},
    {0x0DF8597F, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Basketball Nightmare"},
    {0x1CBB7BF1, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Battlemaniacs"},
    {0xC19430CE, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL | GS_DB_FEATURE_YM2413, "Battle Out Run"},
    {0xB154EC38, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Batman Returns"},
    {0xCAEA8002, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Bonanza Bros."},
    {0xB0FC4577, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Buggy Run"},
    {0xC0E25D62, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "California Games II"},
    {0x23163A12, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Champions of Europe"},
    {0x7E5839A0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Championship Hockey"},
    {0x85CFC9C9, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Chase H.Q."},
    {0x46340C41, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Cheese Cat-Astrophe Starring Speedy Gonzales"},
    {0xDD0E2927, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Chuck Rock"},
    {0xC30E690A, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Chuck Rock II: Son of Chuck"},
    {0x13AC9023, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Cool Spot"},
    {0x71ABEF27, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Daffy Duck in Hollywood"},
    {0xAE4A28D7, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Danan: The Jungle Fighter"},
    {0x42FC3A6E, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Deep Duck Trouble Starring Donald Duck"},
    {0x6C1433F9, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Desert Strike"},
    {0x8370F6CD, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL | GS_DB_FEATURE_YM2413, "Double Hawk"},
    {0x1B10A951, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Dracula (Bram Stoker's)"},
    {0x6C696221, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Dr. Robotnik's Mean Bean Machine"},
    {0x9549FCE4, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Dragon Crystal"},
    {0xC88A5064, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Dragon: The Bruce Lee Story"},
    {0x07306947, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Dynamite Duke"},
    {0x0E1CC1E0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL | GS_DB_FEATURE_YM2413, "Dynamite Dux"},
    {0x6687FAB9, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Ecco the Dolphin"},
    {0xEC788661, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "F1"},
    {0xF6AD7B1D, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Fire & Forget II"},
    {0xCA5C78A5, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Flinstones"},
    {0x38C53916, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Forgotten Worlds"},
    {0x3EC5E627, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Gain Ground"},
    {0xD9190956, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Gauntlet"},
    {0xB67CEB76, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Global Gladiators"},
    {0x05CDC24E, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "G-LOC: Air Battle"},
    {0x48651325, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Golf Mania"},
    {0xEC2DA554, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "GP Rider"},
    {0xCDE13FFB, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Heroes of the Lance"},
    {0xC9DBF936, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Home Alone"},
    {0x64D6AF3B, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Impossible Mission"},
    {0xB4584DDE, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Incredible Crash Dummies"},
    {0xBE9A7071, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Incredible Hulk"},
    {0x8AEB574B, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Indiana Jones and the Last Crusade: The Action Game"},
    {0x8D23587F, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "James Bond 007: The Duel"},
    {0x695A9A15, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Jungle Book"},
    {0x0667ED9F, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Jurassic Park"},
    {0x45C50294, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Jogos de Verao II (BR)"},
    {0x2B435FD6, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Klax"},
    {0x64A585EB, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Krusty's Fun House"},
    {0x24E97200, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Land of Illusion Starring Mickey Mouse"},
    {0x0CA95637, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Laser Ghost"},
    {0xF369B2D8, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Lemmings"},
    {0xCB09F355, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Line of Fire"},
    {0xC352C7EB, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Lion King"},
    {0xA1710F13, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Lucky Dime Caper Starring Donald Duck"},
    {0xBF6F3E5F, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Marble Madness"},
    {0x96FB4D4B, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Master of Darkness"},
    {0x93141463, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Masters of Combat"},
    {0xD7416B83, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Mercs"},
    {0x302DC686, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Mortal Kombat"},
    {0x2663BF18, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Mortal Kombat II"},
    {0x3CD816C6, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Ms. Pac-Man"},
    {0x332A847D, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "NBA Jam [Proto]"},
    {0x1B1D8CC2, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Ninja Gaiden"},
    {0xC660FF34, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "NewZealand Story"},
    {0x6A5A1E39, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Olympic Gold: Barcelona '92"},
    {0x205CAAE8, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Operation Wolf"},
    {0x82EF2A7D, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Ottifants"},
    {0xD6F43DDA, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL | GS_DB_FEATURE_YM2413, "Out Run 3D"},
    {0x3932ADBC, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Out Run Europa"},
    {0xBE57A9A5, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Pac-Mania"},
    {0x95B9EA95, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "PGA Tour Golf"},
    {0xB840A446, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Pit-Fighter"},
    {0xC7A1FDEF, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Populous"},
    {0x0047B615, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Predator 2"},
    {0xA109A6FE, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Power Strike 2"},
    {0x7704287D, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Prince of Persia"},
    {0x5C0B1F0F, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Psychic World"},
    {0x357D4F78, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Putt & Putter"},
    {0xF42E145C, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Quest for the Shaven Yak Starring Ren Hoëk & Stimpy"},
    {0xC172A22C, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Rainbow Islands"},
    {0x426E5C8A, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Rampart"},
    {0x3BE7F641, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Renegade"},
    {0xB876FC74, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Road Rash"},
    {0x9F951756, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "RoboCop 3"},
    {0x8212B754, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "RoboCop Versus The Terminator"},
    {0x1FDAE719, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Running Battle"},
    {0x66388128, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Sagaia"},
    {0x9A8B28EC, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL | GS_DB_FEATURE_YM2413, "Scramble Spirits"},
    {0xA8061AEF, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Sega Chess"},
    {0x296879DD, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Sega World Tournament Golf"},
    {0xF8176918, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Sensible Soccer"},
    {0x3793C01A, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Shadow Dancer"},
    {0x1575581D, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Shadow of the Beast"},
    {0xE0B1AFF8, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Smash TV"},
    {0x97E5BB7D, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Smurfs 2: Travel the World"},
    {0x11C1BC8A, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Sonic Spinball"},
    {0x96B3F29E, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Sonic Blast"},
    {0x5B3B922C, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Sonic The Hedgehog 2 [v0]"},
    {0xD6F2BFCA, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Sonic The Hedgehog 2 [v1]"},
    {0xA908CFF5, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Space Gun"},
    {0xCA1D3752, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Space Harrier"},
    {0xFA8E4CA0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Special Criminal Investigation"},
    {0x5CCC1A65, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Speedball (Virgin)"},
    {0xA57CAD18, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Speedball (Mirrorsoft)"},
    {0x0C7366A0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Speedball 2"},
    {0xEBE45388, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Spider-Man: Return of the Sinister Six"},
    {0xD4B8F66D, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Star Wars"},
    {0x4AB3790F, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Streets of Rage"},
    {0x04E9C089, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Streets of Rage 2"},
    {0xB8F0915A, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Strider II"},
    {0xD8F2F1B9, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Submarine Attack"},
    {0x8DA5C93F, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL | GS_DB_FEATURE_YM2413, "Summer Games"},
    {0x406AA0C2, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Super Kick-Off"},
    {0x54F68C2A, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Super Off Road"},
    {0x1D6244EE, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Super Space Invaders"},
    {0x6F9AC98F, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Superman: The Man of Steel"},
    {0x93CA8152, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "T2: The Arcade Game"},
    {0x7CC3E837, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Taz-Mania"},
    {0x5A1C3DDE, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Tecmo World Cup '93"},
    {0x1A390B93, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL | GS_DB_FEATURE_YM2413, "Tennis Ace"},
    {0xEDC5C012, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Terminator"},
    {0xAC56104F, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Terminator 2: Judgment Day"},
    {0xD1CC08EE, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "The Simpsons: Bart vs. the Space Mutants"},
    {0xF6B2370A, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "The Simpsons: Bart vs. the World"},
    {0xBF7B7285, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Tom & Jerry: The Movie"},
    {0xE5374022, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Trivial Pursuit: Genus Edition"},
    {0xB52D60C8, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL | GS_DB_FEATURE_YM2413, "Ultima IV: Quest of the Avatar"},
    {0x15668CA4, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Ultimate Soccer"},
    {0x912D92AF, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Wimbledon"},
    {0x7F3AFE58, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Wimbledon 2"},
    {0xA20290B6, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Winter Olympics: Lillehammer 94"},
    {0x1F8EFA1D, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Wolfchild"},
    {0x7D7CE80B, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Wonder Boy in Monster World"},
    {0xC9A449B7, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "World Class Leader Board"},
    {0x6E1AD6FD, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "World Cup Italia '90"},
    {0xA6BF8F9E, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "World Cup USA '94"},
    {0xA2A60BC8, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "World Games"},
    {0x2DB21448, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "WWF WrestleMania: Steel Cage Challenge"},
    {0x5C205EE1, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Xenon 2 (Image Works)"},
    {0xEC726C0D, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Xenon 2 (Virgin)"},
    {0x9D9D0A5F, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_PAL, "Zool"},

    // SMS MODE
    {0x6F8E46CF, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "Alex Kidd in Miracle World [SMS-GG]"},
    {0x59840FD6, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "Castle of Illusion - Starring Mickey Mouse [SMS-GG]"},
    {0x9942B69B, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "Castle of Illusion - Starring Mickey Mouse [SMS-GG]"},
    {0x44FBE8F6, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "Chase H.Q. [SMS-GG]"},
    {0xA2F9C7AF, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "Olympic Gold [B] [SMS-GG]"},
    {0x3382D73F, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "Olympic Gold [TW] [SMS-GG]"},
    {0x1D93246E, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "Olympic Gold [A] [SMS-GG]"},
    {0xF037EC00, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "Out Run Europa (US) [SMS-GG]"},
    {0x01EAB89D, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "Out Run Europa [SMS-GG]"},
    {0xE5F789B9, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "Predator 2 [SMS-GG]"},
    {0x311D2863, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "Prince of Persia [A] [SMS-GG]"},
    {0x45F058D6, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "Prince of Persia [B][SMS-GG]"},
    {0x56201996, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "R.C. Grand Prix [SMS-GG]"},
    {0x9C76FB3A, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "Rastan Saga [SMS-GG]"},
    {0x10DBBEF4, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "Super Kick Off [SMS-GG]"},
    {0x7BB81E3D, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "Taito Chase H.Q. [SMS-GG]"},
    {0xC8381DEF, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "Taito Chase H.Q. [SMS-GG]"},
    {0xDA8E95A9, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_SMS_MODE, "WWF Wrestlemania Steel Cage Challenge [SMS-GG]"},
    
    // RAM without battery
    {0xBE31D63F, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_NO_BATTERY | GS_DB_FEATURE_PAL, "Flash, The"},
    {0xB137007A, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_NO_BATTERY, "Desert Speedtrap"},
    {0xC2E111AC, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_NO_BATTERY, "Desert Speedtrap"},
    {0xEC808026, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_NO_BATTERY, "Desert Speedtrap"},

    // KOREAN MAPPER
    {0x89B79E77, GS_DB_KOREAN_MAPPER, GS_DB_FEATURE_NONE, "Dallyeora Pigu-Wang (Korean)"},
    {0x97D03541, GS_DB_KOREAN_MAPPER, GS_DB_FEATURE_NONE, "Sangokushi 3 (Korean)"},
    {0x929222C4, GS_DB_KOREAN_MAPPER, GS_DB_FEATURE_NONE, "Jang Pung II (KR)"},
    {0x18FB98A3, GS_DB_KOREAN_MAPPER, GS_DB_FEATURE_NONE, "Jang Pung 3 (KR)"},

    // MSX MAPPER
    {0x445525E2, GS_DB_MSX_MAPPER, GS_DB_FEATURE_NONE, "Penguin Adventure (KR)"},
    {0x83F0EEDE, GS_DB_MSX_MAPPER, GS_DB_FEATURE_NONE, "Street Master (KR)"},
    {0xA05258F5, GS_DB_MSX_MAPPER, GS_DB_FEATURE_NONE, "Won-Si-In (KR)"},
    {0x06965ED9, GS_DB_MSX_MAPPER, GS_DB_FEATURE_NONE, "F-1 Spirit - The way to Formula-1 (KR)"},
    {0x77EFE84A, GS_DB_MSX_MAPPER, GS_DB_FEATURE_NONE, "Cyborg Z (KR)"},
    {0xF89AF3CC, GS_DB_MSX_MAPPER, GS_DB_FEATURE_NONE, "Knightmare II - The Maze of Galious (KR)"},
    {0x9195C34C, GS_DB_MSX_MAPPER, GS_DB_FEATURE_NONE, "Super Boy 3 (KR)"},
    {0xE316C06D, GS_DB_MSX_MAPPER, GS_DB_FEATURE_NONE, "Nemesis (KR)"},
    {0x0A77FA5E, GS_DB_MSX_MAPPER, GS_DB_FEATURE_NONE, "Nemesis 2 (KR)"},

    // JANGGUN MAPPER
    {0x192949D5, GS_DB_JANGGUN_MAPPER, GS_DB_FEATURE_NONE, "Janggun-ui Adeul (KR)"},

    // JUMBO DAHJEE MAPPER
    {0X16F240D3, GS_DB_JUMBO_DAHJEE_MAPPER, GS_DB_FEATURE_NONE, "Adventure Island [DahJee]"},
    {0XCE5648C3, GS_DB_JUMBO_DAHJEE_MAPPER, GS_DB_FEATURE_NONE, "Bomberman Special [DahJee]"},
    {0X40414556, GS_DB_JUMBO_DAHJEE_MAPPER, GS_DB_FEATURE_NONE, "The Goonies [DahJee]"},
    {0X223397A1, GS_DB_JUMBO_DAHJEE_MAPPER, GS_DB_FEATURE_NONE, "King's Valley"},
    {0X281D2888, GS_DB_JUMBO_DAHJEE_MAPPER, GS_DB_FEATURE_NONE, "Knightmare [Jumbo]"},
    {0X2E7166D5, GS_DB_JUMBO_DAHJEE_MAPPER, GS_DB_FEATURE_NONE, "Legend of Kage, The [DahJee]"},
    {0XDF7CBFA5, GS_DB_JUMBO_DAHJEE_MAPPER, GS_DB_FEATURE_NONE, "Pippols [Jumbo]"},
    {0X306D5F78, GS_DB_JUMBO_DAHJEE_MAPPER, GS_DB_FEATURE_NONE, "Rally-X [DahJee]"},
    {0X29E047CC, GS_DB_JUMBO_DAHJEE_MAPPER, GS_DB_FEATURE_NONE, "Road Fighter [Jumbo]"},
    {0XE0816BB7, GS_DB_JUMBO_DAHJEE_MAPPER, GS_DB_FEATURE_NONE, "Star Soldier [DahJee]"},
    {0X5CBD1163, GS_DB_JUMBO_DAHJEE_MAPPER, GS_DB_FEATURE_NONE, "Tank Battalion [DahJee]"},
    {0XC550B4F0, GS_DB_JUMBO_DAHJEE_MAPPER, GS_DB_FEATURE_NONE, "TwinBee [Jumbo]"},
    {0XFC87463C, GS_DB_JUMBO_DAHJEE_MAPPER, GS_DB_FEATURE_NONE, "Yie Ar Kung-Fu II [DahJee]"},
    {0X7C55057C, GS_DB_JUMBO_DAHJEE_MAPPER, GS_DB_FEATURE_NONE, "Zanac [DahJee]"},

    // SG-1000 with RAM without battery
    {0x092F29D6, GS_DB_SG1000_MAPPER, GS_DB_FEATURE_NO_BATTERY,  "Castle, The (J)"},
    {0x2E366CCF, GS_DB_SG1000_MAPPER, GS_DB_FEATURE_NO_BATTERY,  "Castle, The (T)"},
    {0x223397A1, GS_DB_SG1000_MAPPER, GS_DB_FEATURE_NO_BATTERY,  "King's Valley"},
    {0xAF4F14BC, GS_DB_SG1000_MAPPER, GS_DB_FEATURE_NO_BATTERY,  "Othello (J)"},
    {0x1D1A0CA3, GS_DB_SG1000_MAPPER, GS_DB_FEATURE_NO_BATTERY,  "Othello (T)"},
    {0x49E9718B, GS_DB_SG1000_MAPPER, GS_DB_FEATURE_NONE, "Safari Hunting (JE)"},
    {0x6DC51C01, GS_DB_SG1000_MAPPER, GS_DB_FEATURE_NONE, "Safari Hunting (T)"},

    // YM2413
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "After Burner"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Alex Kidd: The Lost Stars"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Alien Syndrome"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Altered Beast"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Aztec Adventure"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Blade Eagle 3-D"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "BMX Trial Alex Kidd"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Bomber Raid"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "California Games"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Captain Silver"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Casino Games"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "f Master"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Cyborg Hunter"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Double Dragon"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Fantasy Zone II - The tears of OPA-OPA"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Fantasy Zone: The Maze"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Galactic Protector"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Galaxy Force"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Game Box Série Esportes Radicais"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Global Defense"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Golfamania"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Golvellius - Valley of Doom"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Great Golf"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Hoshi wo Sagashite..."},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Kenseiden"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Lord of the Sword"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Maze Hunter 3-D"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Megumi Rescue"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Miracle Warriors: Seal of The Dark Lord"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Mônica no Castelo do Dragão"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Nekkyuu Koushien"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Out Run"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Parlour Games"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Penguin Land"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Phantasy Star"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Poseidon Wars 3-D"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Power Strike"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Rambo III"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Rampage"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Rastan"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Rescue Mission"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "R-Type"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Shanghai"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Shinobi"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Solomon no Kagi - Oujo Rihita no Namida"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Space Harrier 3-D"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "SpellCaster"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Super Basketball"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Super Racing"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Tensai Bakabon"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Thunder Blade"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Time Soldiers"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Turma da Mônica em: O Resgate"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Vigilante"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Wonder Boy III: The Dragon's Trap"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Wonder Boy in Monster Land"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Y's: The Vanished Omens"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Zaxxon 3-D"},
    {0x0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_YM2413, "Zillion II: The Tri Formation"},

    // KOREAN MULTICARTS
    {0xE6C9C046, GS_DB_KOREAN_MSX_SMS_8000_MAPPER, GS_DB_FEATURE_NONE, "Zemina Best 25"},
    {0xD8169FE2, GS_DB_KOREAN_MSX_SMS_8000_MAPPER, GS_DB_FEATURE_NONE, "Zemina Best 39"},
    {0x3C339D9E, GS_DB_KOREAN_MSX_SMS_8000_MAPPER, GS_DB_FEATURE_NONE, "Zemina Best 88"},

    {0x7CD51467, GS_DB_KOREAN_0000_XOR_FF_MAPPER, GS_DB_FEATURE_NONE, "Zemina 4-in-1"},

    {0x4342DB9D, GS_DB_KOREAN_SMS_32KB_2000_MAPPER, GS_DB_FEATURE_NONE, "11 Hap Gam-Boy (KR)"},
    {0x1B3E032E, GS_DB_KOREAN_MSX_32KB_2000_MAPPER, GS_DB_FEATURE_NONE, "2 Hap in 1 (Moai-ui bomul, David-2)"},

    {0xBA5EC0E3, GS_DB_KOREAN_2000_XOR_1F_MAPPER, GS_DB_FEATURE_NONE, "128 Hap (KR)"},
    {0x380D7400, GS_DB_KOREAN_2000_XOR_1F_MAPPER, GS_DB_FEATURE_NONE, "Game Mo-eumjip 188 Hap [v0]"},
    {0xC76601E0, GS_DB_KOREAN_2000_XOR_1F_MAPPER, GS_DB_FEATURE_NONE, "Game Mo-eumjip 188 Hap [v1]"},

    {0x38B3A72F, GS_DB_KOREAN_MSX_8KB_0300_MAPPER, GS_DB_FEATURE_NONE, "Game Chongjiphap 200"},
    {0xD3056492, GS_DB_KOREAN_MSX_8KB_0300_MAPPER, GS_DB_FEATURE_NONE, "Super Game 270 Hap / Jaemissneun-270"},
    {0xAB07ECD4, GS_DB_KOREAN_MSX_8KB_0300_MAPPER, GS_DB_FEATURE_NONE, "Super Game World 260 Hap"},
    {0x0CDE0938, GS_DB_KOREAN_MSX_8KB_0300_MAPPER, GS_DB_FEATURE_NONE, "Super Game World 30 Hap [v0]"},
    {0xE6AD4D4B, GS_DB_KOREAN_MSX_8KB_0300_MAPPER, GS_DB_FEATURE_NONE, "Super Game World 30 Hap [v1]"},
    {0xC29BB8CD, GS_DB_KOREAN_MSX_8KB_0300_MAPPER, GS_DB_FEATURE_NONE, "Super Game World 75 Hap"},
    {0x660BF6EC, GS_DB_KOREAN_MSX_8KB_0300_MAPPER, GS_DB_FEATURE_NONE, "Super Multi Game - Super 75 in 1"},
    {0xEB7790DE, GS_DB_KOREAN_MSX_8KB_0300_MAPPER, GS_DB_FEATURE_NONE, "Super Multi Game - Super 125 in 1"},
    {0xEB7790DE, GS_DB_KOREAN_MSX_8KB_0300_MAPPER, GS_DB_FEATURE_NONE, "Super Multi Game - Super 125 in 1"},

    {0x98AF0236, GS_DB_KOREAN_FFFF_HICOM_MAPPER, GS_DB_FEATURE_NONE, "Hi-Com 3-in-1 The Best Game Collection A"},
    {0x6EBFE1C3, GS_DB_KOREAN_FFFF_HICOM_MAPPER, GS_DB_FEATURE_NONE, "Hi-Com 3-in-1 The Best Game Collection B"},
    {0x81A36A4F, GS_DB_KOREAN_FFFF_HICOM_MAPPER, GS_DB_FEATURE_NONE, "Hi-Com 3-in-1 The Best Game Collection C"},
    {0x8D2D695D, GS_DB_KOREAN_FFFF_HICOM_MAPPER, GS_DB_FEATURE_NONE, "Hi-Com 3-in-1 The Best Game Collection D"},
    {0x82C09B57, GS_DB_KOREAN_FFFF_HICOM_MAPPER, GS_DB_FEATURE_NONE, "Hi-Com 3-in-1 The Best Game Collection E"},
    {0x4088EEB4, GS_DB_KOREAN_FFFF_HICOM_MAPPER, GS_DB_FEATURE_NONE, "Hi-Com 3-in-1 The Best Game Collection F"},
    {0xFBA94148, GS_DB_KOREAN_FFFF_HICOM_MAPPER, GS_DB_FEATURE_NONE, "Hi-Com 8-in-1 The Best Game Collection A"},
    {0x8333C86E, GS_DB_KOREAN_FFFF_HICOM_MAPPER, GS_DB_FEATURE_NONE, "Hi-Com 8-in-1 The Best Game Collection B"},
    {0x00E9809F, GS_DB_KOREAN_FFFF_HICOM_MAPPER, GS_DB_FEATURE_NONE, "Hi-Com 8-in-1 The Best Game Collection C"},

    {0xEDB13847, GS_DB_KOREAN_FFFE_MAPPER, GS_DB_FEATURE_NONE, "Super Game 45"},

    {0x4E202AA2, GS_DB_KOREAN_BFFC_MAPPER, GS_DB_FEATURE_NONE, "Super Game 180"},
    {0xBA5D2776, GS_DB_KOREAN_BFFC_MAPPER, GS_DB_FEATURE_NONE, "Super Game 200"},
    {0xA841C0B7, GS_DB_KOREAN_BFFC_MAPPER, GS_DB_FEATURE_NONE, "Super Game 52 Hap"},

    {0x1B8956D1, GS_DB_KOREAN_FFF3_FFFC_MAPPER, GS_DB_FEATURE_NONE, "Super Game 150"},
    {0xD9Ef7D69, GS_DB_KOREAN_FFF3_FFFC_MAPPER, GS_DB_FEATURE_NONE, "Super Game 270"},

    {0xF60E71EC, GS_DB_KOREAN_MD_FFF5_MAPPER, GS_DB_FEATURE_NONE, "Jaemiissneun Game Mo-eumjip 42 Hap"},
    {0x53904167, GS_DB_KOREAN_MD_FFF5_MAPPER, GS_DB_FEATURE_NONE, "Jaemiissneun Game Mo-eumjip 65 Hap"},
    {0x7F667485, GS_DB_KOREAN_MD_FFF5_MAPPER, GS_DB_FEATURE_NONE, "Mega Mode Super Game 138"},
    {0xC0AC6956, GS_DB_KOREAN_MD_FFF5_MAPPER, GS_DB_FEATURE_NONE, "Pigu-Wang 7 Hap - Jaemiiss-neun Game Mo-eumjip"},

    {0xA67F2A5C, GS_DB_MULTI_4PAK_ALL_ACTION_MAPPER, GS_DB_FEATURE_NONE, "4 PAK All Action"},

    // Requires vint flag on boot
    {0xD9096263, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_INITIAL_VINT, "Sonic's Edusoft [Proto]"},

    // Does not work if YM2413 is enabled
    {0x5359762D, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_DISABLE_YM2413, "Wanted"},

    // Paddle control
    {0xF9DBB533, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_FORCE_JAPAN_SMS | GS_DB_FEATURE_PADDLE | GS_DB_FEATURE_YM2413, "BMX Trial - Alex Kidd"},
    {0xA6FA42D0, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_FORCE_JAPAN_SMS | GS_DB_FEATURE_PADDLE | GS_DB_FEATURE_YM2413, "Galactic Protector"},
    {0x29BC7FAD, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_FORCE_JAPAN_SMS | GS_DB_FEATURE_PADDLE, "Megumi Rescue"},
    {0x315917D4, GS_DB_DEFAULT_MAPPER, GS_DB_FEATURE_FORCE_JAPAN_SMS | GS_DB_FEATURE_PADDLE, "Woody Pop - Shinjinrui no Block Kuzushi"},

    {0, 0, 0, 0}
};

const uint32_t kCRC32_tab[] = 
{
    0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f,
    0xe963a535, 0x9e6495a3, 0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
    0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 0x1db71064, 0x6ab020f2,
    0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
    0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9,
    0xfa0f3d63, 0x8d080df5, 0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
    0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b, 0x35b5a8fa, 0x42b2986c,
    0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
    0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423,
    0xcfba9599, 0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
    0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d, 0x76dc4190, 0x01db7106,
    0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
    0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d,
    0x91646c97, 0xe6635c01, 0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
    0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950,
    0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
    0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7,
    0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
    0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa,
    0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
    0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81,
    0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
    0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683, 0xe3630b12, 0x94643b84,
    0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
    0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb,
    0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
    0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5, 0xd6d6a3e8, 0xa1d1937e,
    0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
    0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55,
    0x316e8eef, 0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
    0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe, 0xb2bd0b28,
    0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
    0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f,
    0x72076785, 0x05005713, 0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
    0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 0x86d3d2d4, 0xf1d4e242,
    0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
    0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69,
    0x616bffd3, 0x166ccf45, 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
    0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc,
    0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
    0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693,
    0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
    0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};

inline u32 CalculateCRC32(u32 crc, const u8 *buf, int size)
{
    const u8 *p;

    p = buf;
    crc = crc ^ ~0U;

    while (size--)
        crc = kCRC32_tab[(crc ^ *p++) & 0xFF] ^ (crc >> 8);

    return crc ^ ~0U;
}

#endif	/* GAME_DB_H */

