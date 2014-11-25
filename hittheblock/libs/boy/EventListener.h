#pragma once
namespace Boy{
	class Event;
	class EventDispatcher;
	class EventListener
	{
	public:
		EventListener();
		~EventListener();
		virtual void handleEvent(Event *evt);
		void init(EventDispatcher *evtDpr);
	};
}