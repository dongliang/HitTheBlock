#pragma once
#include "EventListener.h"

#include <vector>
namespace Boy{
	class Event;
	class EventDispatcher
	{
	public: 

		void addEventListener(EventListener *listener);
		void removeEventListener(EventListener * listener);
		bool hasEventListener(EventListener *listener);
		void setChanged();
		void dispatchEvent(Event *evt);

	protected:
		std::vector<EventListener *>  mListeners;
		/*解释：是否发送事件的开关，只有值为true时，dispatchEvent才会触发事件，
			触发事件后设置该值为false;
			举例：比如 在每次子弹射中怪物时，我都会调用 dispatchEvent事件，
			只有当怪物血减为0时，我会调用setChanged方法，
			此时dispatchEvent会将事件发送出去。*/
		bool mChanged;
	};
}