#pragma once
namespace Boy{
    class EventDispatcher;
	class Event
	{

	public:
		//����������๹�캯���е���init ��ʼ�� target type
		Event();
		~Event();
		EventDispatcher * Target() const;
		void Target(EventDispatcher * val);
		int Type() const;
		void Type(int val);
		virtual void init()=0;

	protected:
		EventDispatcher * mTarget;
		int mType;
	};
}