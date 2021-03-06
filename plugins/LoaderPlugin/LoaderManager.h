#pragma once

class LoaderManager
{
public:
  LoaderManager( const std::wstring& pluginPath );
  ~LoaderManager(void);

  void Init(AmPlugin* p  );
  void Exit( );
  void Main(AmPlugin* p  );

protected:
  void Learn(AmPlugin* p, bool isPrivileged );
  void UnLearn(AmPlugin* p, const std::wstring& lpName );

  bool RemoveCommand(AmPlugin* p, const std::wstring& name );
  bool AddCommand(AmPlugin* p, const std::wstring& name, const std::wstring& path );

  typedef std::map< std::wstring, std::wstring > OPENAS_NAMES;
  OPENAS_NAMES  m_openAs;

  OPENAS_NAMES::const_iterator Find(const std::wstring& name ) const;

protected:
  // the XML file.
  std::wstring m_lpFilePath;
  std::wstring m_pluginPath;
  std::wstring m_thisPath;

  const std::wstring& GetPluginPath() const{
    return m_pluginPath;
  }
  const std::wstring& GetThisPath() const{
    return m_thisPath;
  }

  bool LoadXML(AmPlugin* p  );
  bool SaveXML() const;

  bool SaveLUAFile( std::wstring& fileName, 
                    const std::wstring command,
                    const std::wstring appPath,
                    bool isPrivileged
                  );

  bool RemoveActionIfInList(AmPlugin* p, const std::wstring& lowerName, bool deleteFileIfExists );
  static std::wstring GetUnLearnCommand( const std::wstring& lowerName);
};
