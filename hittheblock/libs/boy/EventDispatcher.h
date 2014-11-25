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
		/*���ͣ��Ƿ����¼��Ŀ��أ�ֻ��ֵΪtrueʱ��dispatchEvent�Żᴥ���¼���
			�����¼������ø�ֵΪfalse;
			���������� ��ÿ���ӵ����й���ʱ���Ҷ������ dispatchEvent�¼���
			ֻ�е�����Ѫ��Ϊ0ʱ���һ����setChanged������
			��ʱdispatchEvent�Ὣ�¼����ͳ�ȥ��*/
		bool mChanged;
	};
}