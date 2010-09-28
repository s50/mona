#include "VnodeCacher.h"
#include <monapi.h>
using namespace std;

typedef pair<Vnode*, EntriesMap*> vpair;
typedef pair<string, Vnode*> spair;
typedef vector<Vnode*> Vnodes;

VnodeCacher::VnodeCacher()
{
    directories_ = new DirectoriesMap();

}

VnodeCacher::~VnodeCacher()
{
    Vnodes vnodes;
    // enumrate all Vnodes
    for (DirectoriesMap::const_iterator it = directories_->begin(); it != directories_->end(); ++it)
    {
        vnodes.push_back((*it).first);

        EntriesMap* entries = (*it).second;
        for (EntriesMap::iterator i = entries->begin(); i != entries->end(); i++)
        {
            vnodes.push_back((*i).second);
        }
        delete entries;
    }
    // enumrate unique Vnodes
    sort(vnodes.begin(), vnodes.end());
    Vnodes::iterator v = unique(vnodes.begin(), vnodes.end());
    vnodes.erase(v ,vnodes.end());
    for (Vnodes::const_iterator it = vnodes.begin(); it != vnodes.end(); ++it)
    {
        Vnode* v = (*it);
        // todo. v->fs will be destroyed before coming this line.
//        v->fs->destroyVnode(v);
    }
    delete directories_;
}

void VnodeCacher::enumCaches(Vnode* directory, std::vector<std::string>& caches)
{
    DirectoriesMap::iterator it = directories_->find(directory);
    if (it == directories_->end()) {
        return;
    }
    EntriesMap* entries = it->second;
    for (EntriesMap::const_iterator eit = entries->begin(); eit != entries->end(); ++eit) {
        caches.push_back(eit->first);
    }
}

Vnode* VnodeCacher::lookup(Vnode* directory, const string& name)
{
    if (directory->type != Vnode::DIRECTORY) return NULL;
    DirectoriesMap::iterator it = directories_->find(directory);
    EntriesMap* entries;
    if (it == directories_->end())
    {
        return NULL;
    }
    else
    {
        entries = (*it).second;
    }
    EntriesMap::iterator eit = entries->find(name);
    return eit == entries->end() ? NULL : (*eit).second;
}

void VnodeCacher::add(Vnode* directory, const string& name, Vnode* entry)
{
    if (directory->type != Vnode::DIRECTORY) return;

    DirectoriesMap::iterator it = directories_->find(directory);
    EntriesMap* entries;
    if (it == directories_->end())
    {
        entries = new EntriesMap;
        directories_->insert(vpair(directory, entries));
    }
    else
    {
        entries = (*it).second;
    }

    EntriesMap::iterator eit = entries->find(name);
    if (eit != entries->end())
    {
        _printf("%s:%d already exists vnode\n", __FILE__, __LINE__);
        exit(-1);
    }

    entries->insert(spair(name, entry));
    return;
}

void VnodeCacher::remove(Vnode* directory, const string& name)
{
    logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
    ASSERT(directory->type == Vnode::DIRECTORY);
    logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
    DirectoriesMap::iterator it = directories_->find(directory);
    logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
    EntriesMap* entries;
    logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
    if (it == directories_->end()) {
    logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
        return;
    } else {
    logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
        entries = (*it).second;
    logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
    }
    logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
    entries->erase(name);
    logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
    return;
}
