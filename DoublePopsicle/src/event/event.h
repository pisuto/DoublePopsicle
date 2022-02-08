#pragma once

#include <string>
#include <functional>

#include "../core/core.h"

namespace dp {

	// 目前事件会被立即响应

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
	};

	enum EventCategory {
		None = 0,
		EventCategoryApp = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4),
	};

#define EVENT_CLASS_TYPE(type) static EventType get_static_type() { return EventType::##type; } \
								virtual EventType get_event_type() const override { return get_static_type(); } \
								virtual const char* get_event_name() const override { return #type; } \

#define EVENT_CLASS_CATEGORY(category) virtual int get_category_flags() const override { return category; }


	class DP_API Event
	{
	public:
		virtual EventType get_event_type() const = 0;
		virtual const char* get_event_name() const = 0;
		virtual int get_category_flags() const = 0;
		virtual std::string to_string() const { return get_event_name(); }

		inline bool is_in_category(EventCategory category) {
			return get_category_flags() & category;
		}

	protected:
		bool mbHandled = false;
	};

	
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: mEvent(event) {}

		// 执行eventfn，返回事件处理的结果
		template<typename T>
		bool dispatch(EventFn<T> func) {
			if (mEvent.get_event_type() == T::get_static_type()) {
				mEvent.mbHandled = func(*(T*)&mEvent);
				return true;
			}
			return false;
		}

	private:
		Event& mEvent;
	};

	inline std::ostream& operator<<(std::ostream& out, const Event& e) {
		return out << e.to_string();
	}
}