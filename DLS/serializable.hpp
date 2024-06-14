namespace dls {
	class serializable {
        protected:
			virtual void save() = 0;
			virtual void load() = 0;
	};
}
