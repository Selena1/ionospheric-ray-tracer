//============================================================================
// Name        : Application.h
// Author      : Rian van Gijlswijk
// Description : Main application file. Responsible for starting, running and
//				 stopping the simulation
//============================================================================

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <list>
#include <boost/thread.hpp>
#include "../exporter/Data.h"
#include "../scene/SceneManager.h"
#include "../tracer/Ray.h"

namespace raytracer {
namespace core {

	using namespace scene;
	using namespace exporter;
	using namespace tracer;

	class Application {

		public:
			static Application& getInstance() {
				static Application instance;
				return instance;
			}
			void init();
			void start();
			void run();
			void stop();
			void addToDataset(Data dat);
			void incrementTracing();
			SceneManager getSceneManager();
			list<Data> dataSet;
			list<Ray> rays;

		private:
			Application() {
				isRunning = false;
				numTracings = 0;
			}
			Application(Application const&);      // Don't Implement.
			void operator = (Application const&); // Don't implement
			void createScene();
			void flushScene();
			bool isRunning;
			SceneManager scm;
			int numTracings;

	};

} /* namespace core */
} /* namespace raytracer */

#endif /* APPLICATION_H_ */
