#pragma once
namespace Boy{
    class EventDispatcher;
	class Event
	{

	public:
		//最好是在子类构造函数中调用init 初始化 target type
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