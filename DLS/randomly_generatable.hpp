namespace dls {
	template <typename T>
	class randomly_generatable {
        protected:
			virtual T random() = 0;
			virtual T random_range(T const&, T const&) = 0;
	};
}
