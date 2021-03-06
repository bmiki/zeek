// See the file  in the main distribution directory for copyright.

#include "BitTorrent.h"
#include "BitTorrentTracker.h"
#include "plugin/Plugin.h"
#include "analyzer/Component.h"

namespace plugin {
namespace Zeek_BitTorrent {

class Plugin : public plugin::Plugin {
public:
	plugin::Configuration Configure()
		{
		AddComponent(new ::analyzer::Component("BitTorrent", ::analyzer::bittorrent::BitTorrent_Analyzer::Instantiate));
		AddComponent(new ::analyzer::Component("BitTorrentTracker", ::analyzer::bittorrent::BitTorrentTracker_Analyzer::Instantiate));

		plugin::Configuration config;
		config.name = "Zeek::BitTorrent";
		config.description = "BitTorrent Analyzer";
		return config;
		}
} plugin;

}
}
