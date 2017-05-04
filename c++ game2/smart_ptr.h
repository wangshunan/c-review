#pragma once
#include <memory>

#ifndef PTR
#define PTR( NAME )\
	class NAME;\
	typedef std::shared_ptr< NAME > NAME##Ptr;\
	typedef std::shared_ptr< const NAME > NAME##CPtr;\
	typedef std::weak_ptr< NAME > NAME##WPtr;\
	typedef std::unique_ptr< NAME > NAME##UPtr;\

#endif

template <typename T>
bool PointsToValidOrExpiredObject(const std::weak_ptr<T>& w) {
    return w.owner_before(std::weak_ptr<T>{}) ||
           std::weak_ptr<T>{}.owner_before(w);
}