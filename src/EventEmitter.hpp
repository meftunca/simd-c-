#ifndef EVENT_EMITTER_HPP
#define EVENT_EMITTER_HPP

#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <typeindex>
#include <typeinfo>
#include <vector>

/*
  EventEmitter is a class that allows you to emit events and listen to them.
  It is a singleton class, so you can only have one instance of it.
  It is thread-safe.
  Supporting multiple instances of EventEmitter is not a priority.
  - The event name is a string.
  - The event data is a void  pointer.
  - The event listener is a function that takes a void  pointer.


  Actions:
  - on(event, listener) - Register a listener for an event.
  - off(event, listener) - Unregister a listener for an event.
  - emit(event, data) - Emit an event with data.
  - once(event, listener) - Register a listener for an event that will be called only once.

  Example:
  EventEmitter::getInstance().on("event", [](void* data) {
    // Do something with data
  });
  EventEmitter::getInstance().emit("event", data);

*/

class EventEmitter final
{
  public:
  // Get the instance of EventEmitter.
  static EventEmitter& getInstance();

  // Register a listener for an event.
  void on(const std::string& event, const std::function<void(void *)>& listener);

  // Unregister a listener for an event.
  void off(const std::string& event, const std::function<void(void *)>& listener);

  // Emit an event with data.
  void emit(const std::string& event, void *data);

  // Register a listener for an event that will be called only once.
  // void once(const std::string& event, const std::function<void(void *)>& listener);

  private:
  // Private constructor to prevent creating multiple instances.
  EventEmitter() = default;

  // Private copy constructor to prevent creating multiple instances.
  EventEmitter(const EventEmitter&) = delete;

  // Private assignment operator to prevent creating multiple instances.
  EventEmitter& operator=(const EventEmitter&) = delete;

  // Private destructor to prevent creating multiple instances.
  ~EventEmitter() = default;

  // The map of events and their listeners.
  std::map<std::string, std::vector<std::function<void(void *)>>> m_listeners;

  // The mutex to make the class thread-safe.
  std::mutex m_mutex;
};

void
EventEmitter::on(const std::string& event, const std::function<void(void *)>& listener)
{
  std::lock_guard<std::mutex> lock(m_mutex);
  m_listeners[event].push_back(listener);
}

void
EventEmitter::off(const std::string& event, const std::function<void(void *)>& listener)
{
  std::lock_guard<std::mutex> lock(m_mutex);
  m_listeners[event].clear();
}

void
EventEmitter::emit(const std::string& event, void *data)
{
  std::lock_guard<std::mutex> lock(m_mutex);
  for( auto& listener : m_listeners[event] ) { listener(data); }
}

#endif // EVENT_EMITTER_HPP