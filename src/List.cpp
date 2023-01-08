#include <fstream>

#include "List.h"
#include "Achievement.h"

// TODO: add categories for achievements



List::List(const std::string &file_path) {
    std::fstream file;
    file.open(file_path);

    if (file.is_open()) {
        std::string line;
        std::vector<std::string> parts;
        int i{0};
        int line_count{5};

        // FIXME: currently our input file contains an extra line to get around the issue,
        // FIXME: however at the very last line we never reach (i>3) since it will be 3 and the last line wont get included in the output
        while (getline(file, line, ';')) {
            if (i > 3) {
                i = 0;
                Achievement achievement = Achievement(parts[0], parts[1], parts[2], std::stof(parts[3]));
                m_achievements.emplace_back(achievement);
                parts.clear();
            }

            parts.emplace_back(line);
            i++;
        }
    } else {
        std::cerr << "File didn't open successfully when creating the list!" << '\n';
    }

    file.close();

    for (auto i : m_achievements) {
        std::cout << i << '\n';
    }

    std::cout << '\n';
}

void List::status() {
    // check if obj vector is empty
    int count{0};
    for (const auto &achievement: m_achievements) {
        count++;
    }
    if (count == 0) {
        std::cerr << "You haven't added any achievements. Returning to main menu." << '\n';
        return;
    } else {
        std::cout << "Total: " << count << " rendered." << "\n";
    }

    // output
    std::cout << "############################################" << '\n';
    std::cout << "\t\t\t\tAchievements" << '\n';
    std::cout << "############################################" << '\n';
    std::cout << "ID" << '\t' << "Description" << '\t' << "Type" << '\t' << "Category" << '\t' << "Progress" << '\t'
              << '\n';
    std::cout << "--------------------------------------------" << '\n';
    // display all achievements
    for (const auto &achievement: m_achievements) {
        std::cout << achievement << '\n';
        std::cout << "--------------------------------------------" << '\n';
    }
    std::cout << "############################################" << '\n';
}

void List::add() {
    // assign id based on count
    int count{1};
    for (const auto &achievement: m_achievements) {
        count++;
    }

    std::string description{};
    std::string type{'X'};
    std::string category{};
    float progress{0.0};

    // gather input
    std::cout << "Achievement adding format: Description - Type - Category - Progress" << '\n';
    std::cout << "Description:" << '\n';
    std::cin >> description;
    std::cout << "Type: " << "\t" << "[C]ompletion, [D]ate, [T]imer" << '\n';
    std::cin >> type;
    std::cout << "Category: " << '\t' << "(Enter none if empty)" << '\n';
    std::cin >> category;
    // TODO: dont ask for progress if the category type is timer based and work out what to ask here based on category
    std::cout << "Progress: " << '\t' << "(Leave empty if you haven't started yet)" << '\n';
    std::cin >> progress;
    // TODO: guarantee correct input data type by using std::cin.ignore and if (std::cin >> x) which reads if data was succesfully read into variable
    // add new obj
    // FIXME: add id count here
    Achievement achievement{description, type, category, progress};
    m_achievements.push_back(achievement);
}

void List::remove() {
    bool removing{true};
    while (removing) {
        // output format
        std::cout << "Which achievement would you like to remove?" << '\n';
        for (const auto &achievement: m_achievements) {
            std::cout << achievement.id << '\t',
                    std::cout << achievement.description << '\t',
                    std::cout << achievement.type << '\t',
                    std::cout << achievement.category << '\t';
        }

        // which to remove
        int remove_choice{0};
        std::cin >> remove_choice;

        // removal
        for (const auto &achievement: m_achievements) {
            if (remove_choice == achievement.id) {
                m_achievements.erase((m_achievements.begin() + achievement.id - 1));
            }
        }

        // ask if continue removal
        std::cout << "Keep removing? y/N?" << '\n';
        char response{'y'};
        std::cin >> response;
        if (response == 'n' || response == 'N') {
            removing = false;
        }
        // TODO: guarantee that we can only input yY, nN

        // reassign id's after each removal
        int count{1};
        for (auto &achievement: m_achievements) {
            achievement.id = count;
            count++;
        }
    }
}

void List::edit() {
    bool is_editing{true};
    while (is_editing) {
        std::cout << "Which achievement would you like to edit?" << '\n';
        std::cout << "(0) to quit" << '\n';
        for (const auto &achievement: m_achievements) {
            std::cout << achievement.id << '\t',
                    std::cout << achievement.description << '\t';
        }

        // which achievement to edit
        int edit_choice{1};
        std::cin >> edit_choice;

        for (auto &achievement: m_achievements) {
            if (edit_choice == achievement.id) {

                bool is_editing_part{true};
                while (is_editing_part) {
                    // TODO: maybe count amount of achievements, and assign quit button based on that so its fancy?
                    std::cout << "Which part of the achievement would you like to edit?" << '\n';
                    std::cout << "(1-4) to edit" << '\n';
                    std::cout << "(0) to quit" << '\n';
                    std::cout << achievement.description << '\t';

                    int part_choice{0};
                    std::cin >> part_choice;

                    if (part_choice == 1) {
                        std::cout << "Enter new description: " << '\n';

                        std::string new_description;
                        std::cin >> new_description;

                        achievement.description = new_description;
                    } else if (part_choice == 2) {
                        // TODO: think over what kind of types there should be
                        std::cout << "Choose a new type: " << '\n';
                        std::cout << "[C]ompletion - " << '\n'
                                  << "[D]ate" << '\n'
                                  << "[T]imer " << '\n';

                        char new_type;
                        std::cin >> new_type;
                        // Description - Type - Category - Progress
                    } else if (part_choice == 3) {
                        std::cout << "Enter new category: " << '\n';

                        std::string new_category;
                        std::cin >> new_category;

                        achievement.category = new_category;
                    } else if (part_choice == 4) {
                        std::cout << "Enter new progress: " << '\n';

                        float new_progress;
                        std::cin >> new_progress;

                        achievement.progress = new_progress;
                    } else if (part_choice == 0) {
                        std::cout << "Returning to edit" << '\n';
                        is_editing_part = false;
                    } else {
                        std::cerr << "Choose valid achievement part to edit." << '\n';
                    }
                }
            } else if (edit_choice == 0) {
                is_editing = false;
            }
        }
    }
}