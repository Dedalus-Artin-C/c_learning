//简单的调用indicators库


// #include <chrono>
// #include <indicators/indeterminate_progress_bar.hpp>
// #include <indicators/cursor_control.hpp>
// #include <indicators/termcolor.hpp>
// #include <thread>

// int main() {
//   indicators::IndeterminateProgressBar bar{
//       indicators::option::BarWidth{40},
//       indicators::option::Start{"["},
//       indicators::option::Fill{"·"},
//       indicators::option::Lead{"<==>"},
//       indicators::option::End{"]"},
//       indicators::option::PostfixText{"Checking for Updates"},
//       indicators::option::ForegroundColor{indicators::Color::yellow},
//       indicators::option::FontStyles{
//           std::vector<indicators::FontStyle>{indicators::FontStyle::bold}}
//   };

//   indicators::show_console_cursor(false);

//   auto job = [&bar]() {
//     std::this_thread::sleep_for(std::chrono::milliseconds(10000));
//     bar.mark_as_completed();
//     std::cout << termcolor::bold << termcolor::green 
//         << "System is up to date!\n" << termcolor::reset;
//   };
//   std::thread job_completion_thread(job);

//   // Update bar state
//   while (!bar.is_completed()) {
//     bar.tick();
//     std::this_thread::sleep_for(std::chrono::milliseconds(100));
//   }

//   job_completion_thread.join();
  
//   indicators::show_console_cursor(true);  
//   return 0;
// }

#include <indicators/progress_bar.hpp>
#include <thread>
#include <chrono>

int main() {
  using namespace indicators;
  ProgressBar bar{
    option::BarWidth{50},
    option::Start{"["},
    option::Fill{"*"},
    option::Lead{">>>"},
    option::Remainder{"~"},
    option::End{"]"},
    option::PostfixText{"Extracting Archive"},
    option::ForegroundColor{Color::green},
    option::FontStyles{std::vector<FontStyle>{FontStyle::bold}}
  };
  
  // Update bar state
  while (true) {
    bar.tick();
    if (bar.is_completed())
      break;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}